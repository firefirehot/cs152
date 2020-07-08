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
%right ASSIGN
%left OR AND
%right NOT
%left EQ NEQ LT GT LTE GTE
%left PLUS MINUS
%left MULT DIV MOD
%right UMINUS
%left L_SQUARE_BRACKET R_SQUARE_BRACKET
%left R_PAREN L_PAREN

%start program

 
%%
program:/*epsilon*/
	{printf("Program->epsilon \n");} 
	| functions
	{printf("Program->FUNCTION functions");}
	;
functions: function
	| function functions
        ;
function: FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarationsWsemi END_PARAMS BEGIN_LOCALS declarationsWsemi END_LOCALS BEGIN_BODY statementzWsemi END_BODY
        {printf("function-> FUNCTION IDENT SEMICOLON BEGIN_PARAMS (declaration SEMICOLON declarations)? END_PARAMS BEGIN_LOCALS (declaration SEMICOLON declarations)? END_LOCALS BEGIN_BODY statement SEMICOLON statements END_BODY \n");}
        ;
declarationsWsemi: /*epsilon*/
        | declaration SEMICOLON declarationsWsemi
        ;
declaration: idents COLON ARRAY R_SQUARE_BRACKET NUMBER L_SQUARE_BRACKET OF INTEGER
        {printf("Declaration -> identifier (COMMA identifiers)? COLON ARRAY R_SQUARE_BRACKET NUMBER L_SQUARE_BRACKET OF INTEGER \n");}
	| idents COLON INTEGER
	{printf("Declaration -> identifier (COMMA identifiers)? COLON INTEGER \n");} 
        ;
idents: ident idents
	| ident
        ;
ident: IDENT COMMA
        ;
statementzWsemi: statement SEMICOLON statementzWsemi 
	{printf("\n");}
	| statement SEMICOLON
	;
statement: var ASSIGN expression
        {printf("statement-> var ASSIGN expression\n");}
	| IF boolExpression THEN statementzWsemi ENDIF
        {printf("IF -> bool-expression THEN statement (SEMICOLON statements)? ENDIF \n");}
	| IF boolExpression THEN statementzWsemi ELSE statementzWsemi ENDIF
	{printf("IF bool-expression THEN statement (SEMICOLON statements)? ELSE statement (SEMICOLON statements)? ENDIF \n");}
	| WHILE boolExpression BEGINLOOP statementzWsemi ENDLOOP
	{printf(" \n");}
        | DO BEGINLOOP statementzWsemi ENDLOOP WHILE boolExpression
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
	| relationAndExpression OR boolExpression
	{printf(" \n");} 
        ;
relationAndExpression: relationExpression
	{printf(" \n");}
        | relationExpression AND relationAndExpression 
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
expressionzWcomma:/*epsilon*/
	{printf(" \n");} 
	| expression
        {printf(" \n");}
        |expression expressionCommaChain
	{printf("\n");}
	;
expressionCommaChain: COMMA expression expressionCommaChain
	| COMMA expression
	;
expression: multiplicativeExpression
        {printf(" \n");}
        | multiplicativeExpression PLUS expression
        {printf(" \n");}
        | multiplicativeExpression MINUS expression
	{printf(" \n");}
	;
multiplicativeExpression: term
        {printf(" \n");}
        | term MOD multiplicativeExpression
        {printf(" \n");}
        | term DIV multiplicativeExpression 
        {printf(" \n");}
        | term MULT multiplicativeExpression 
        {printf(" \n");}
	;
term: var
        {printf(" \n");}
        | MINUS var %prec UMINUS
        {printf(" \n");}
        | NUMBER
        {printf(" \n");}
        | MINUS NUMBER %prec UMINUS
        {printf(" \n");}
        | L_PAREN expression R_PAREN
        {printf(" \n");}
        | MINUS L_PAREN expression R_PAREN %prec UMINUS
        {printf(" \n");}
        | IDENT L_PAREN expressionzWcomma R_PAREN
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
   printf("** Line %d, position %d: %s\n ", row_c, col_c, msg);
}

