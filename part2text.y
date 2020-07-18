%{
%}

%skeleton "lalr1.cc"
%require "3.0.4"
%defines
%define api.token.constructor
%define api.value.type variant
%define parse.error verbose
%locations


%code requires
{
 #include <list>
 #include <functional>
 #include <string>
using namespace std;
/*ENTER STRUCT here */

}

%code
{

#include "parser.tab.hh"

	/* you may need these header files 
	 * add more header file if you need more
	 */
#include <sstream>
#include <map>
#include <regex>
#include <set>
yy::parser::symbol_type yylex();
void yyerror(const char *msg);
 extern long row_c;
 extern long col_c;
 extern FILE * yyin;
void yyerror(const char * msg);
string errorArray[30];
int errorArrayCount = 0;
bool no_error = true;
}

%token END 0 "end of file";
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN SUB ADD MULT DIV MOD EQ NEQ LT GT LTE GTE IDENT NUMBER SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN
%type<string> IDENT
%type<int> NUMBER
%right ASSIGN
%left OR AND
%right NOT
%left EQ NEQ LT GT LTE GTE
%left ADD SUB
%left MULT DIV MOD
%right UMINUS
%left L_SQUARE_BRACKET R_SQUARE_BRACKET
%left R_PAREN L_PAREN
%type <string> program function declaration statement declarationsWsemi statementzWsemi  



%%

%start prog_start;

prog_start: program {if(no_error) cout << $1 << endl;}
	;

program:/*epsilon*/
	{$$ = "";} 
	| function program
	{$$ = $1 + "\n" + $2;}
	;
function: FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarationsWsemi END_PARAMS BEGIN_LOCALS declarationsWsemi END_LOCALS BEGIN_BODY statementzWsemi END_BODY
	{$$ = "func" + $2 + "\n";
	$$ += $5;
	$$ += $8;
	$$ += $11;
	$$ += "endfunc \n";
	}
	| FUNCTION error
	{$$ = "";}
        ;
declarationsWsemi: /*epsilon*/
	{$$ = "";}
        | declaration SEMICOLON declarationsWsemi
	{
	$$ = $1;
	}
	| error SEMICOLON
	{$$ = "";}
	| declaration error declarationsWsemi
        ;
declaration: idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
	{$$ = "declaration \n";}
	| idents COLON INTEGER
        {$$ = "declaration \n";}
	;
idents: IDENT COMMA idents
	| IDENT
        ;
statementzWsemi: statement SEMICOLON statementzWsemi
	{$$ = $1;} 
	| statement SEMICOLON
	{$$ = $1;}
	| error SEMICOLON
	{$$ = "";}
	| statement error
	{$$ = "";}
	;
statement: var ASSIGN expression
        {$$ = "statement \n";}
	| IF boolExpression THEN statementzWsemi ENDIF
	{$$ = "statement \n";}  
	| IF boolExpression THEN statementzWsemi ELSE statementzWsemi ENDIF
	{$$ = "statement \n";}  
	| WHILE boolExpression BEGINLOOP statementzWsemi ENDLOOP
	{$$ = "statement \n";}  
        | DO BEGINLOOP statementzWsemi ENDLOOP WHILE boolExpression
	{$$ = "statement \n";}  
        | READ varzWcomma
	{$$ = "statement \n";}  
        | WRITE varzWcomma 
	{$$ = "statement \n";}  
	| RETURN expression
	{$$ = "statement \n";}  
        ;
boolExpression: relationAndExpression
        //{cout << "boolExpression -> relationAndExpression \n";}
	| relationAndExpression OR boolExpression
	//{cout << "boolExpression -> relationAndExpression OR boolExpression \n";} 
        ;
relationAndExpression: relationExpression
	//{cout << "relationAndExpression -> relationExpression \n";}
        | relationExpression AND relationAndExpression 
	//{cout << "relationAndExpression -> relationExpression AND relationExpression \n";}
        ;
relationExpression: expression comp expression
	//{cout << "relationExpression -> expression comp expression \n";}
        |  NOT expression comp expression  
	//{cout << "relationExpression -> NOT expression comp expression \n";}
        |  TRUE
	//{cout << "relationExpression -> TRUE \n";}
        |  NOT TRUE
	//{cout << "relationExpression -> NOT TRUE \n";}
        |  FALSE
	//{cout << "relationExpression -> FALSE \n";}
        |  NOT FALSE
	//{cout << "relationExpression -> NOT FALSE \n";}
        |  L_PAREN boolExpression R_PAREN
	//{cout << "relationExpression -> L_PAREN boolExpression R_PAREN \n";}
        |  NOT L_PAREN boolExpression R_PAREN
	//{cout << "relationExpression -> NOT L_PAREN boolExpression R_PAREN \n";} 
	;
comp: EQ
        //{cout << "comp -> EQ \n";}
        | NEQ
        //{cout << "comp -> NEQ \n";}
        | LT
        //{cout << "comp -> LT \n";}
        | GT
        //{cout << "comp -> GT \n";}
        | LTE
        //{cout << "comp -> LTE \n";}
        | GTE
	//{cout << "comp -> GTE \n";}
	;
expressionzWcomma:/*epsilon*/ 
	| expression
        |expression expressionCommaChain
	;
expressionCommaChain: COMMA expression expressionCommaChain
	| COMMA expression
	;
expression: multiplicativeExpression
       // {cout << "expression -> multiplicativeExpression \n";}
        | multiplicativeExpression ADD expression
        //{cout << "expression -> multiplicativeExpression PLUS expression \n";}
        | multiplicativeExpression SUB expression
	//{cout << "expression -> mulitplicativeExpression MINUS expression \n";}
	;
multiplicativeExpression: term
        //{cout << "multiplicativeExpression -> term \n";}
        | term MOD multiplicativeExpression
        //{cout << "multiplicativeExpression -> term MOD multiplicativeExpression \n";}
        | term DIV multiplicativeExpression 
        //{cout << "multiplicativeExpression -> term DIV multiplicativeExpression \n";}
        | term MULT multiplicativeExpression 
        //{cout << "multiplicativeExpression -> term MULT multiplicativeExpression \n";}
	;
term: var
        //{cout << "term -> var \n";}
        | SUB var %prec UMINUS
        //{cout << "term -> SUB var \n";}
        | NUMBER
        //{cout << "term -> NUMBER \n";}
        | SUB NUMBER %prec UMINUS 
        //{cout << "term -> SUB NUMBER \n";}
        | L_PAREN expression R_PAREN
        //{cout << "term -> L_PAREN expression R_PAREN \n";}
        | SUB L_PAREN expression R_PAREN %prec UMINUS
        //{cout << "term -> SUB L_PAREN expression R_PAREN \n";}
        | IDENT L_PAREN expressionzWcomma R_PAREN
	//{cout << "term -> IDENT L_PAREN (expression)? (COMMA expressions)? R_PAREN \n";}
	;
varzWcomma: var COMMA varzWcomma
	| var
	;
var: IDENT
	//{cout << "var -> IDENT %s \n";}
	| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET
	//{cout << "var -> IDENT %s L_SQUARE_BRACKET expression R_SQUARE_BRACKET \n";}
	;


%%

   int main(int argc, char *argv[])
{
	yy::parser p; 
	
        for(int count = 0; count < errorArrayCount; count++){
                cout << (errorArray[count]);
       }
   return p.parse();
}

void yy::parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}


void yyerror(const char *msg) {
	no_error = false;
   if(errorArrayCount < 30){
	errorArray[errorArrayCount] = "Line " + to_string(row_c) + " position " + to_string(col_c) + ": " + msg+ "\n";
	errorArrayCount++;	
}
}

