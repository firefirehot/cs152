%{
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 void yyerror(const char *msg);
 extern long row_c;
 extern long col_c;
 extern FILE * yyin;
void yyerror(const char * msg);
char * errorArray[30];
int errorArrayCount = 0;
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
%left ADD SUB
%left MULT DIV MOD
%right UMINUS
%left L_SQUARE_BRACKET R_SQUARE_BRACKET
%left R_PAREN L_PAREN

%start program

 
%%
program:/*epsilon*/
	{printf("Program->epsilon \n");} 
	| functions
	{printf("Program->FUNCTION functions \n");}
	;
functions: function
	| function functions
        ;
function: FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarationsWsemi END_PARAMS BEGIN_LOCALS declarationsWsemi END_LOCALS BEGIN_BODY statementzWsemi END_BODY
        {printf("function-> FUNCTION IDENT SEMICOLON BEGIN_PARAMS (declaration SEMICOLON declarations)? END_PARAMS BEGIN_LOCALS (declaration SEMICOLON declarations)? END_LOCALS BEGIN_BODY statement SEMICOLON statements END_BODY \n");}
        ;
declarationsWsemi: /*epsilon*/
        | declaration SEMICOLON declarationsWsemi
	| error SEMICOLON
        ;
declaration: idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
        {printf("Declaration -> identifier (COMMA identifiers)? COLON ARRAY R_SQUARE_BRACKET NUMBER L_SQUARE_BRACKET OF INTEGER \n");}
	| idents COLON INTEGER
	{printf("Declaration -> identifier (COMMA identifiers)? COLON INTEGER \n");} 
        ;
idents: IDENT COMMA idents
	| IDENT
        ;
statementzWsemi: statement SEMICOLON statementzWsemi 
	| statement SEMICOLON
	;
statement: var ASSIGN expression
        {printf("statement-> var ASSIGN expression\n");}
	| IF boolExpression THEN statementzWsemi ENDIF
        {printf("statement -> IF bool-expression THEN statement (SEMICOLON statements)? ENDIF \n");}
	| IF boolExpression THEN statementzWsemi ELSE statementzWsemi ENDIF
	{printf("statement -> IF bool-expression THEN statement (SEMICOLON statements)? ELSE statement (SEMICOLON statements)? ENDIF \n");}
	| WHILE boolExpression BEGINLOOP statementzWsemi ENDLOOP
	{printf("statement -> WHILE boolExpression BEGINLOOP statement (SEMICOLON statements)? ENDLOOP \n");}
        | DO BEGINLOOP statementzWsemi ENDLOOP WHILE boolExpression
        {printf("statement -> DO BEGINLOOP statement (SEMICOLON statements)? ENDLOOP WHILE boolExpression \n");}
        | READ varzWcomma
	{printf("statement -> READ var (COMMA vars)? \n");}
        | WRITE varzWcomma 
        {printf("statement -> WRITE var (COMMA vars)? \n");}                                                                    | CONTINUE
        {printf("statement -> CONTINUE \n");}                                                                    
	| RETURN expression
	{printf("statement -> RETURN expression \n");}
        ;
boolExpression: relationAndExpression
        {printf("boolExpression -> relationAndExpression \n");}
	| relationAndExpression OR boolExpression
	{printf("boolExpression -> relationAndExpression OR boolExpression \n");} 
        ;
relationAndExpression: relationExpression
	{printf("relationAndExpression -> relationExpression \n");}
        | relationExpression AND relationAndExpression 
	{printf("relationAndExpression -> relationExpression AND relationExpression \n");}
        ;
relationExpression: expression comp expression
	{printf("relationExpression -> expression comp expression \n");}
        |  NOT expression comp expression  
	{printf("relationExpression -> NOT expression comp expression \n");}
        |  TRUE
	{printf("relationExpression -> TRUE \n");}
        |  NOT TRUE
	{printf("relationExpression -> NOT TRUE \n");}
        |  FALSE
	{printf("relationExpression -> FALSE \n");}
        |  NOT FALSE
	{printf("relationExpression -> NOT FALSE \n");}
        |  L_PAREN boolExpression R_PAREN
	{printf("relationExpression -> L_PAREN boolExpression R_PAREN \n");}
        |  NOT L_PAREN boolExpression R_PAREN
	{printf("relationExpression -> NOT L_PAREN boolExpression R_PAREN \n");} 
	;
comp: EQ
        {printf("comp -> EQ \n");}
        | NEQ
        {printf("comp -> NEQ \n");}
        | LT
        {printf("comp -> LT \n");}
        | GT
        {printf("comp -> GT \n");}
        | LTE
        {printf("comp -> LTE \n");}
        | GTE
	{printf("comp -> GTE \n");}
	;
expressionzWcomma:/*epsilon*/ 
	| expression
        |expression expressionCommaChain
	;
expressionCommaChain: COMMA expression expressionCommaChain
	| COMMA expression
	;
expression: multiplicativeExpression
        {printf("expression -> multiplicativeExpression \n");}
        | multiplicativeExpression ADD expression
        {printf("expression -> multiplicativeExpression PLUS expression \n");}
        | multiplicativeExpression SUB expression
	{printf("expression -> mulitplicativeExpression MINUS expression \n");}
	;
multiplicativeExpression: term
        {printf("multiplicativeExpression -> term \n");}
        | term MOD multiplicativeExpression
        {printf("multiplicativeExpression -> term MOD multiplicativeExpression \n");}
        | term DIV multiplicativeExpression 
        {printf("multiplicativeExpression -> term DIV multiplicativeExpression \n");}
        | term MULT multiplicativeExpression 
        {printf("multiplicativeExpression -> term MULT multiplicativeExpression \n");}
	;
term: var
        {printf("term -> var \n");}
        | SUB var %prec UMINUS
        {printf("term -> SUB var \n");}
        | NUMBER
        {printf("term -> NUMBER \n");}
        | SUB NUMBER %prec UMINUS 
        {printf("term -> SUB NUMBER \n");}
        | L_PAREN expression R_PAREN
        {printf("term -> L_PAREN expression R_PAREN \n");}
        | SUB L_PAREN expression R_PAREN %prec UMINUS
        {printf("term -> SUB L_PAREN expression R_PAREN \n");}
        | IDENT L_PAREN expressionzWcomma R_PAREN
	{printf("term -> IDENT %s L_PAREN (expression)? (COMMA expressions)? R_PAREN \n", $1);}
	;
varzWcomma: var COMMA varzWcomma
	| var
	;
var: IDENT
	{printf("var -> IDENT %s \n", $1);}
	| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET
	{printf("var -> IDENT %s L_SQUARE_BRACKET expression R_SQUARE_BRACKET \n", $1);}
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
    int count = 0;
        while( count < errorArrayCount){
                printf("%s \n", errorArray[count]);
		free(errorArray[count]);
                count++;
       }
   return 0;
}


void yyerror(const char *msg) {
	char  tempChar[200];
	sprintf(tempChar,"** Line %d, position %d: %s\n ", row_c, col_c, msg);
   if(errorArrayCount < 30){
	errorArray[errorArrayCount] = malloc(sizeof(tempChar));
	strcpy(errorArray[errorArrayCount], tempChar);
	errorArrayCount++;	
}
printf("%s \n", tempChar);
}

