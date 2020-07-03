%{
 #include <stdio.h>
 #include <stdlib.h>

 void yyerror(const char *msg);
 extern long row_c;
 extern long col_c;
 extern FILE * yyin;
void yyerror(const char * msg);
%}

%union{
  char* cval;
  int ival;
}

%error-verbose
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN SUB ADD MULT DIV MOD EQ NEQ LT GT LTE GTE IDENT NUMBER SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN
%type<cval> IDENT
%type<ival> NUMBER
%left PLUS MINUS
%left MULT DIV
%start program

 
%%
program: functions
	{printf(" \n");}
	;
functions: /*epsilon*/
        {printf(" \n");}
	| function functions
        {printf(" \n");}
        ;
function: FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarationsWsemi ENDPARAMS BEGIN_LOCALS declarationsWsemi END_LOCALS BEGIN_BODY statementzWsemi ENDBODY
        {printf(" \n");}
        ;
declarationsWsemi: /*epsilon*/
        {printf(" \n");}
        | declaration declarations SEMICOLON
        ;
declarations: declaration declarations
        ;
declaration: idents COLON ARRAY R_SQUARE_BRACKET NUMBER L_SQUARE_BRACKET OF INTEGER
        {printf("Declaration -> identifier [COMMA identifier]* COLON ARRAY R_SQUARE_BRACKET NUMBER L_SQUARE_BRACKET OF INTEGER \n");}
	| idents COLON INTEGER
	{printf("Declaration -> identifier [COMMA identifier]* COLON INTEGER \n")} 
        ;
idents: ident idents
        {printf(" \n");}
        ;
ident: IDENT COMMA
        {printf(" \n");}
        ;
statementzWsemi: statementz 
	{printf("\n");}
	;
statementz: statment SEMICOLON statementz
        {printf(" \n");}
	| statement SEMICOLON 
        ;
statement: --var-- ASSIGN --expression--
        {printf(" \n");}
	| IF boolExpression THEN statementzWsemi ENDIF
        {printf(" \n");}
	| IF boolExpression THEN statementzWsemi ELSE statementzWsemi ENDIF
	{printf(" \n");}
	| WHILE boolExpression BEGIN_LOOP statementzWsemi END_LOOP
	{printf(" \n");}
        | DO BEGIN_LOOP statementzWsemi END_LOOP WHILE boolExpression
        {printf(" \n");}
        | READ varzWcomma
	{printf(" \n");}
        | WRITE varzWcomma 
        {printf(" \n");}                                                                    
	| CONTINUE
        {printf(" \n");}                                                                    
	| RETURN expression
        ;
boolExpression: relationAndExpression
        {printf(" \n");}
	| relationAndExpression OR RelationAndExpression
	{printf(" \n");} 
        ;
relationAndExpression: relationExpression
	{printf(" \n");}
        | relationExpression AND relationExpression 
	{printf(" \n");}
        ;
relationExpression: expression comp expression
	{printf(" \n");}
        |  NOT expression comp expression  
	{printf(" \n");}
        |  TRUE
	{printf(" \n");}
        |  NOT TRUE
	{printf(" \n");}
        |  FALSE
	{printf(" \n");}
        |  NOT FALSE
	{printf(" \n");}
        |  L_PAREN boolExpression R_PAREN
	{printf(" \n");}
        |  NOT L_PAREN boolExpression R_PAREN
	{printf(" \n");} 
	;
comp: EQ
        {printf(" \n");}
        | NEQ
        {printf(" \n");}
        | LT
        {printf(" \n");}
        | GT
        {printf(" \n");}
        | LTE
        {printf(" \n");}
        | GTE
	;
expressionzWcomma: expression
        {printf(" \n");}
        |expression expressionCommaChain
expressionCommaChain: COMMA expression expressionCommaChain
	| COMMA expression
	;
expression: mutiplicativeExpression
        {printf(" \n");}
        | mutiplicativeExpression PLUS mutiplicativeExpression
        {printf(" \n");}
        | mutiplicativeExpression PLUS mutiplicativeExpression MINUS mutiplicativeExpression
        {printf(" \n");}
        | mutiplicativeExpression MINUS mutiplicativeExpression
	;
multiplicativeExpression: term
        {printf(" \n");}
        | term MOD term
        {printf(" \n");}
        | term DIV term
        {printf(" \n");}
        | term MULT term
        {printf(" \n");}
        | term MULT term DIV term
        {printf(" \n");}
        | term MULT term MOD term
        {printf(" \n");}
        | term DIV term MOD term
        {printf(" \n");}
        | term MULT term DIV term MOD term
	;
term: var
        {printf(" \n");}
        | MINUS var
        {printf(" \n");}
        | NUMBER
        {printf(" \n");}
        | MINUS NUMBER
        {printf(" \n");}
        | L_PAREN expression R_PAREN
        {printf(" \n");}
        | MINUS L_PAREN expression R_PAREN
        {printf(" \n");}
        | IDENT L_PAREN expressionzWcommaChai R_PAREN
	;
varzWcomma: var varzWcomma
	{printf(" \n");}
	| var
	{printf(" \n");}
	;
var: IDENT
	{printf(" \n");}
	| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET
	;
%%

int main(int argc, char **argv) {
   if (argc > 1) {
      yyin = fopen(argv[1], "r");
      if (yyin == NULL){
         printf("syntax: %s filename\n", argv[0]);
      }//end if
   }//end if
   yyparse(); // Calls yylex() for tokens.
   return 0;
}

void yyerror(const char *msg) {
   printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}

