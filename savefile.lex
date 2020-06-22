
%{




%}
DIGIT [0-9]
%%
{DIGIT}+ {printf("NUMBER %s \n",yytext);}
"+" {printf("PLUS \n");}
"-" {printf("MINUS \n");}
"*" {printf("MULT \n");}
"/" {printf("DIV \n");}
"(" {printf("L_PAREN \n");}
")" {printf("R_PAREN \n");}
"=" {printf("EQUAL \n");}
. {printf("unrecognized symbol. \n"); exit(0);}

%%
