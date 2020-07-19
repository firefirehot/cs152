%{
#include <iostream>
#define YY_DECL yy::parser::symbol_type yylex()
#include "parser.tab.h"
static yy::location loc;
long row_c = 1;
long col_c = 1;
%}

%option noyywrap 

%{
#define YY_USER_ACTION loc.columns(yyleng);
%}

DIGIT [0-9]
ID ([a-zA-Z][a-zA-Z0-9_]*[a-zA-Z0-9])|([a-zA-Z])
BADIDONE [0-9_][a-zA-Z0-9_]*[a-zA-Z0-9]
BADIDTWO [a-zA-Z][a-zA-Z0-9_]*_


%%

%{
loc.step(); 
%}


{DIGIT}+ { col_c = col_c + yyleng; return yy::parser::make_NUMBER(atoi(yytext),loc);}
##.* {col_c = col_c + yyleng;}
"function" {col_c = col_c + yyleng; return yy::parser::make_FUNCTION(loc);}
"beginparams" {col_c = col_c + yyleng;return yy::parser::make_BEGIN_PARAMS(loc);}
"endparams" {col_c = col_c + yyleng;return yy::parser::make_END_PARAMS(loc);}
"beginlocals" {col_c = col_c + yyleng; return yy::parser::make_BEGIN_LOCALS(loc);}
"endlocals" {col_c = col_c + yyleng; return yy::parser::make_END_LOCALS(loc);}
"beginbody" {col_c = col_c + yyleng;return yy::parser::make_BEGIN_BODY(loc);}
"endbody" {col_c = col_c + yyleng; return yy::parser::make_END_BODY(loc);}
"integer" {col_c = col_c + yyleng; return yy::parser::make_INTEGER(loc);}
"array" {col_c = col_c + yyleng; return yy::parser::make_ARRAY(loc);}
"of" {col_c = col_c + yyleng;return yy::parser::make_OF(loc);}
"if" {col_c = col_c + yyleng; return yy::parser::make_IF(loc);}
"then" {col_c = col_c + yyleng; return yy::parser::make_THEN(loc);}
"endif" {col_c = col_c + yyleng; return yy::parser::make_ENDIF(loc);}
"else" {col_c = col_c + yyleng; return yy::parser::make_ELSE(loc);}
"while" {col_c = col_c + yyleng; return yy::parser::make_WHILE(loc);}
"do" {col_c = col_c + yyleng; return yy::parser::make_DO(loc);}
"beginloop" {col_c = col_c + yyleng; return yy::parser::make_BEGINLOOP(loc);}
"endloop" {col_c = col_c + yyleng; return yy::parser::make_ENDLOOP(loc);}
"continue" {col_c = col_c + yyleng; return yy::parser::make_CONTINUE(loc);}
"read" {col_c = col_c + yyleng; return yy::parser::make_READ(loc);}
"write" {col_c = col_c + yyleng; return yy::parser::make_WRITE(loc);}
"and" {col_c = col_c + yyleng; return yy::parser::make_AND(loc);}
"or" {col_c = col_c + yyleng; return yy::parser::make_OR(loc);} 
"not" {col_c = col_c + yyleng; return yy::parser::make_NOT(loc);} 
"true" {col_c = col_c + yyleng; return yy::parser::make_TRUE(loc);} 
"false" {col_c = col_c + yyleng; return yy::parser::make_FALSE(loc);} 
"return" {col_c = col_c + yyleng; return yy::parser::make_RETURN(loc);} 
"-" {col_c = col_c + yyleng; return yy::parser::make_SUB(loc);} 
"+" {col_c = col_c + yyleng; return yy::parser::make_ADD(loc);} 
"*" {col_c = col_c + yyleng; return yy::parser::make_MULT(loc);} 
"/" {col_c = col_c + yyleng; return yy::parser::make_DIV(loc);} 
"%" {col_c = col_c + yyleng; return yy::parser::make_MOD(loc);} 
"==" {col_c = col_c + yyleng; return yy::parser::make_EQ(loc);} 
"<>" {col_c = col_c + yyleng; return yy::parser::make_NEQ(loc);} 
"<" {col_c = col_c + yyleng; return yy::parser::make_LT(loc);} 
">" {col_c = col_c + yyleng; return yy::parser::make_GT(loc);} 
"<=" {col_c = col_c + yyleng; return yy::parser::make_LTE(loc);} 
">=" {col_c = col_c + yyleng; return yy::parser::make_GTE(loc);} 
{ID} {col_c = col_c + yyleng; return yy::parser::make_IDENT(yytext, loc);} 
";" {col_c = col_c + yyleng; return yy::parser::make_SEMICOLON(loc);} 
":" {col_c = col_c + yyleng; return yy::parser::make_COLON(loc);} 
"," {col_c = col_c + yyleng; return yy::parser::make_COMMA(loc);} 
"(" {col_c = col_c + yyleng; return yy::parser::make_L_PAREN(loc);} 
")" {col_c = col_c + yyleng; return yy::parser::make_R_PAREN(loc);} 
"]" {col_c = col_c + yyleng; return yy::parser::make_R_SQUARE_BRACKET(loc);} 
"[" {col_c = col_c + yyleng; return yy::parser::make_L_SQUARE_BRACKET(loc);}  
":=" {col_c = col_c + yyleng; return yy::parser::make_ASSIGN(loc);} 
{BADIDONE} {printf("INVALID IDENTIFIER");exit(0);}
{BADIDTWO} {printf("INVALID IDENTIFIER at row %d and column %d. User entered %s \n ", col_c,row_c, yytext);exit(0);}
\n {row_c = row_c + 1; col_c = 1;}
[ \t]+ {col_c = col_c + yyleng;}

 <<EOF>>	{return yy::parser::make_END(loc);}
. {printf("unrecognized symbol at line %d and column %d. User entered: %s \n", row_c,col_c,yytext); exit(0);}
%%


