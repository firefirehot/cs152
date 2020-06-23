%{
//c code
long row_c = 1;
long col_c = 1;

%}
DIGIT [0-9]
ID [a-zA-Z][a-zA-Z0-9_]*[a-zA-Z0-9]
BADIDONE [0-9_][a-zA-Z0-9_]*[a-zA-Z0-9]
BADIDTWO [a-zA-Z][a-zA-Z0-9_]*_


%%


{DIGIT}+ {printf("NUMBER %s \n",yytext); col_c = col_c + yyleng;}

"function" {printf("FUNCTION \n");col_c = col_c + yyleng;}
"beginparams" {printf("BEGIN_PARAMS \n");col_c = col_c + yyleng;}
"endparams" {printf("END_PARAMS \n");col_c = col_c + yyleng;}
"beginlocals" {printf("BEIN_LOCALS \n");col_c = col_c + yyleng;}
"endlocals" {printf("END_LOCALS \n");col_c = col_c + yyleng;}
"beginbody" {printf("BEGIN_BODY \n");col_c = col_c + yyleng;}
"endbody" {printf("END_BODY \n");col_c = col_c + yyleng;}
"integer" {printf("INTEGER \n");col_c = col_c + yyleng;}
"array" {printf("ARRAY \n");col_c = col_c + yyleng;}
"of" {printf("OF \n");col_c = col_c + yyleng;}
"if" {printf("IF \n");col_c = col_c + yyleng;}
"then" {printf("THEN \n");col_c = col_c + yyleng;}
"endif" {printf("ENDIF \n");col_c = col_c + yyleng;}
"else" {printf("ELSE \n");col_c = col_c + yyleng;}
"while" {printf("WHILE \n");col_c = col_c + yyleng;}
"do" {printf("DO \n");col_c = col_c + yyleng;}
"beginloop" {printf("BEGINLOOP \n");col_c = col_c + yyleng;}
"endloop" {printf("ENDLOOP \n");col_c = col_c + yyleng;}
"continue" {printf("CONTINUE \n");col_c = col_c + yyleng;}
"read" {printf("READ \n");col_c = col_c + yyleng;}
"write" {printf("WRITE \n");col_c = col_c + yyleng;}
"and" {printf("AND \n");col_c = col_c + yyleng;}
"or" {printf("OR \n");col_c = col_c + yyleng;} 
"not" {printf("NOT \n");col_c = col_c + yyleng;} 
"true" {printf("TRUE \n");col_c = col_c + yyleng;} 
"false" {printf("FALSE \n");col_c = col_c + yyleng;} 
"return" {printf("RETURN \n");col_c = col_c + yyleng;} 
"-" {printf("SUB \n");col_c = col_c + yyleng;} 
"+" {printf("ADD \n");col_c = col_c + yyleng;} 
"*" {printf("MULT\n");col_c = col_c + yyleng;} 
"/" {printf("DIV \n");col_c = col_c + yyleng;} 
"%" {printf("MOD \n");col_c = col_c + yyleng;} 
"==" {printf("EQ \n");col_c = col_c + yyleng;} 
"<>" {printf("NEQ \n");col_c = col_c + yyleng;} 
"<" {printf("LT \n");col_c = col_c + yyleng;} 
">" {printf("GT \n");col_c = col_c + yyleng;} 
"<=" {printf("LTE \n");col_c = col_c + yyleng;} 
">=" {printf("GTE \n");col_c = col_c + yyleng;} 
{ID} {printf("IDENT %s\n", yytext);col_c = col_c + yyleng;} 
{DIGIT}+ {printf("NUMBER %s\n", yytext);col_c = col_c + yyleng;}
";" {printf("SEMICOLON \n");col_c = col_c + yyleng;} 
":" {printf("COLON \n");col_c = col_c + yyleng;} 
"," {printf("COMMA \n");col_c = col_c + yyleng;} 
"(" {printf("L_PAREN \n");col_c = col_c + yyleng;} 
")" {printf("R_PAREN \n");col_c = col_c + yyleng;} 
"]" {printf("L_SQUARE_BRACKET\n");col_c = col_c + yyleng;} 
"[" {printf("R_SQUARE_BRACKET\n");col_c = col_c + yyleng;}  
":=" {printf("ASSIGN \n");col_c = col_c + yyleng;} 
{BADIDONE} {printf("INVALID IDENTIFIER");exit(0);}
{BADIDTWO} {printf("INVALID IDENTIFIER at row %d and column %d. User entered %s \n ", col_c,row_c, yytext);exit(0);}
"\n" {col_c = col_c + 1; row_c = 1;}
[\t]+ {col_c = col_c + yyleng;}


. {printf("unrecognized symbol at line %d and column %d. User entered: %s \n", col_c,row_c,yytext); exit(0);}





%%
