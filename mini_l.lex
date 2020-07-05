%{
//c code
#include "y.tab.h"
long row_c = 1;
long col_c = 1;

%}

DIGIT [0-9]
ID ([a-zA-Z][a-zA-Z0-9_]*[a-zA-Z0-9])|([a-zA-Z])
BADIDONE [0-9_][a-zA-Z0-9_]*[a-zA-Z0-9]
BADIDTWO [a-zA-Z][a-zA-Z0-9_]*_


%%


{DIGIT}+ { col_c = col_c + yyleng; yylval.ival = atoi(yytext); return NUMBER;}
##.* {col_c = col_c + yyleng;}
"function" {col_c = col_c + yyleng; return FUNCTION;}
"beginparams" {col_c = col_c + yyleng;return BEGIN_PARAMS;}
"endparams" {col_c = col_c + yyleng;return END_PARAMS;}
"beginlocals" {col_c = col_c + yyleng; return BEGIN_LOCALS;}
"endlocals" {col_c = col_c + yyleng; return END_LOCALS;}
"beginbody" {col_c = col_c + yyleng;return BEGIN_BODY;}
"endbody" {col_c = col_c + yyleng; return END_BODY;}
"integer" {col_c = col_c + yyleng; return END_BODY;}
"array" {col_c = col_c + yyleng; return ARRAY;}
"of" {col_c = col_c + yyleng;return OF;}
"if" {col_c = col_c + yyleng; return IF;}
"then" {col_c = col_c + yyleng; return THEN;}
"endif" {col_c = col_c + yyleng; return ENDIF;}
"else" {col_c = col_c + yyleng; return ELSE;}
"while" {col_c = col_c + yyleng; return WHILE;}
"do" {col_c = col_c + yyleng; return DO;}
"beginloop" {col_c = col_c + yyleng; return BEGINLOOP;}
"endloop" {col_c = col_c + yyleng; return ENDLOOP;}
"continue" {col_c = col_c + yyleng; return CONTINUE;}
"read" {col_c = col_c + yyleng; return READ;}
"write" {col_c = col_c + yyleng; return WRITE;}
"and" {col_c = col_c + yyleng; return AND;}
"or" {col_c = col_c + yyleng; return OR;} 
"not" {col_c = col_c + yyleng; return NOT;} 
"true" {col_c = col_c + yyleng; return TRUE;} 
"false" {col_c = col_c + yyleng; return FALSE;} 
"return" {col_c = col_c + yyleng; return RETURN;} 
"-" {col_c = col_c + yyleng; return SUB;} 
"+" {col_c = col_c + yyleng; return ADD;} 
"*" {col_c = col_c + yyleng; return MULT;} 
"/" {col_c = col_c + yyleng; return DIV;} 
"%" {col_c = col_c + yyleng; return MOD;} 
"==" {col_c = col_c + yyleng; return EQ;} 
"<>" {col_c = col_c + yyleng; return NEQ;} 
"<" {col_c = col_c + yyleng; return LT;} 
">" {col_c = col_c + yyleng; return GT;} 
"<=" {col_c = col_c + yyleng; return LTE;} 
">=" {col_c = col_c + yyleng; return GTE;} 
{ID} {col_c = col_c + yyleng; yylval.cval = yytext; return IDENT;} 
";" {col_c = col_c + yyleng; return SEMICOLON;} 
":" {col_c = col_c + yyleng; return COLON;} 
"," {col_c = col_c + yyleng; return COMMA;} 
"(" {col_c = col_c + yyleng; return L_PAREN;} 
")" {col_c = col_c + yyleng; return R_PAREN;} 
"]" {col_c = col_c + yyleng; return R_SQUARE_BRACKET;} 
"[" {col_c = col_c + yyleng; return L_SQUARE_BRACKET;}  
":=" {col_c = col_c + yyleng; return ASSIGN;} 
{BADIDONE} {printf("INVALID IDENTIFIER");exit(0);}
{BADIDTWO} {printf("INVALID IDENTIFIER at row %d and column %d. User entered %s \n ", col_c,row_c, yytext);exit(0);}
\n {row_c = row_c + 1; col_c = 1;}
[ \t]+ {col_c = col_c + yyleng;}


. {printf("unrecognized symbol at line %d and column %d. User entered: %s \n", row_c,col_c,yytext); exit(0);}
%%


