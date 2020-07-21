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
struct exp_str{
	string code;
	string place;
	string begin;
	string after;
};
}

%code
{

#include "parser.tab.h"

	/* you may need these header files 
	 * add more header file if you need more
	 */
#include <sstream>
#include <map>
#include <regex>
#include <set>
yy::parser::symbol_type yylex();
void myerror(string msg);
extern long row_c;
extern long col_c;
 extern FILE * yyin;
void yyerror(const char * msg);
string errorArray[30];
bool no_error = true;
long tempNum = 0;
long labelNum = 0;
map <string,int> varTable;
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
%type <string> program function declaration declarationsWsemi statementzWsemi idents 
%type<exp_str> expression multiplicativeExpression term var expressionzWcomma expressionCommaChain boolExpression statment

%%

%start prog_start;

prog_start: program {if(no_error) cout << $1 << endl;}
	;

program:/*epsilon*/
	{$$ = "";} 
	| function program
	{$$ = $1 + "\n" + $2;}
	;
function: FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarationsWsemi END_PARAMS BEGIN_LOCALS declarationsWsemi END_LOCALS BEGIN_BODY statementzWsemi endTrigger
	{$$ = "func " + $2 + "\n";
	$$ += $5;
	$$ += $8;
	$$ += $11;
	$$ += "endfunc \n";
	}
	| FUNCTION error
	{$$ = "";}
        ;
endTrigger: END_BODY
	{	
	for(std::map<string,int>::iterator it = varTable.begin(); it != varTable.end(); it++){
	it->second = it->second - 1;	
	}
	}
declarationsWsemi: /*epsilon*/
	{$$ = "";}
        | declaration SEMICOLON declarationsWsemi
	{
	$$ = $1 + $3;
	}
	| error SEMICOLON
	{$$ = "";}
	| declaration error declarationsWsemi
        ;
declaration: idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
	{$$ = "'[]' " + $1 + ", " + to_string($5);}
	| idents COLON INTEGER
        {$$ = ". " + $1 + "\n";}
	;
idents: IDENT COMMA idents
	{$$ = $1 + $3;
	if (!varTable.insert(make_pair($1,1)).second){
	myerror("Variable already existed.");
	}
	}
	| IDENT
	{$$ = $1;
	if (!varTable.insert(make_pair($1,1)).second){
	myerror("Variable already existed.");
	}
	}
        ;
statementzWsemi: statement SEMICOLON statementzWsemi
	{$$ = $1.code + $3; } 
	| statement SEMICOLON
	{$$ = $1.code;}
	| error SEMICOLON
	{$$ = "";}
	| statement error
	{$$ = "";}
	;
statement: var ASSIGN expression
        {$$.code = $3.code + $1.code + "= " + $1.place + ", " + $3.place + "\n";}
	| IF boolExpression THEN statementzWsemi ENDIF
	{
	$$.begin = "label" + to_string(labelNum);
	labelNum++;
	$$.after = "label" + to_string(labelNum);
	labelNum++;
	$$.code = ": " + $$.begin + "\n";
	$$.code += $2.code;
	$$.code += "! " + $2.place + ", " + $2.place + "\n";
	$$.code += "?:= " + $4.after + ", " + $2.place + "\n";
	$$.code += $4.code;
	$$.code = ": " + $$.after + "\n";
	}  
	| IF boolExpression THEN statementzWsemi ELSE statementzWsemi ENDIF
	{
	 $$.begin = "label" + to_string(labelNum);
        labelNum++;
        $$.after = "label" + to_string(labelNum);
        labelNum++;
        $$.code = ": " + $$.begin + "\n";
        $$.code += $2.code;
        $$.code += "! " + $2.place + ", " + $2.place + "\n"; 
        $$.code += "?:= " + $5.begin + ", " + $2.place + "\n";
        $$.code += $4.code;
	$$.code += ":= " + $5.after;
        $$.code = ": " + $$.after + "\n";
	}  
	| WHILE boolExpression BEGINLOOP statementzWsemi ENDLOOP
	{$$.begin = "label" + to_string(labelNum);
        labelNum++;
        $$.after = "label" + to_string(labelNum);
        labelNum++;
	$$.code = ": " + $$.begin + "\n";
	
	$$.code += $2.code;
        $$.code += "! " + $2.place + ", " + $2.place + "\n";
        $$.code += "?:= " + $$.after + ", " + $2.place + "\n";
	$$.code += $4.code;
	$$.code += ":= " + $$.begin;
	
	$$.code += ": " + $$.after + "\n";
	}  
        | DO BEGINLOOP statementzWsemi ENDLOOP WHILE boolExpression
	{$$.begin = "label" + to_string(labelNum);
        labelNum++;
        $$.after = "label" + to_string(labelNum);
        labelNum++;
	$$.code = ": " + $$.begin + "\n";

	$$.code += $3.code;
	$$.code += $6.code;
        $$.code += "?:= " + $$.begin + ", " + $2.place + "\n";	

	$$.code += ": " + $$.after + "\n";
	}  
        | READ varzWcomma
	{$$ = "statement \n";}  
        | WRITE varzWcomma 
	{$$ = "statement \n";}  
	| RETURN expression
	{$$ = "statement \n";}  
        ;
boolExpression: relationAndExpression
        {$$.code = $1.code; $$.place = $1.place;}
	| relationAndExpression OR boolExpression
	{
	$$.place = "temp_" + to_string(tempNum);
        tempNum++;
        $$.code = $1.code + $3.code + ". " + $$.place + "\n" + "|| " + $$.place + ", " + $1.place + ", " + $3.place + "\n";
	} 
        ;
relationAndExpression: relationExpression
        {$$.code = $1.code; $$.place = $1.place;}
	| relationExpression AND relationAndExpression 
        {            
	$$.place = "temp_" + to_string(tempNum);
        tempNum++;
        $$.code = $1.code + $3.code + ". " + $$.place + "\n" + "&& " + $$.place + ", " + $1.place + ", " + $3.place + "\n";
	}
	;
relationExpression: expression comp expression
        {                                                          
	$$.place = "temp_" + to_string(tempNum);
        tempNum++;
        $$.code = $1.code + $3.code + ". " + $$.place + "\n" + $2 + " " + $$.place + ", " + $1.place + ", " + $3.place + "\n";
        }
	|  NOT expression comp expression  
         {                                                                                    
	$$.place = "temp_" + to_string(tempNum);
        tempNum++;
        $$.code = $2.code + "! " + $2.place + ", " + $2.place + "\n" + $4.code + ". " + $$.place + "\n" + $3 +" " + $$.place + ", " + $2.place + ", " + $4.place + "\n";
	}
	|  TRUE
	{$$.code = ""; $$.place = "1";}
        |  NOT TRUE
	{$$.code = ""; $$.place = "0";}
        |  FALSE
	{$$.code = ""; $$.place = "0";}
        |  NOT FALSE
	{$$.code = ""; $$.place = "1";}
        |  L_PAREN boolExpression R_PAREN
	{
	$$.code = $2.code + "= " + $$.place + ", " + $2.place + "\n";
	$$.place = $2.place;
	}
        |  NOT L_PAREN boolExpression R_PAREN
	{
	$$.code = $3.place + "! " + $3.place + ", " + $3.place + "\n" + "= " + $$.place + ", " + $3.place + "\n";
        $$.place = $3.place;
	} 
	;
comp: EQ
        {$$ = "=="}
        | NEQ
        {$$ = "!="}
        | LT
        {$$ = "<"}
        | GT
        {$$ = ">";}
        | LTE
        {$$ = "<=";}
        | GTE
	{$$ = ">=";}
	;
expressionzWcomma:/*epsilon*/ 
	{$$.code = "";}	
	| expression
	{$$.code = $1.code;}
        |expression expressionCommaChain
	{$$.code = $1.code + $2.code;}
	;
expressionCommaChain: COMMA expression expressionCommaChain
	{$$.code = $2.code + $3.code;}
	| COMMA expression
	{$$.code = $2.code;}
	;
expression: multiplicativeExpression
        {$$.code = $1.code; $$.place = $1.place;}
        | multiplicativeExpression ADD expression
        {
	$$.place = "temp_" + to_string(tempNum);
	tempNum++;
	$$.code = $1.code + $3.code + ". " + $$.place + "\n" + "+ " + $$.place + ", " + $1.place + ", " + $3.place + "\n";
	 }
        | multiplicativeExpression SUB expression
	{
	$$.place = "temp_" + to_string(tempNum);
        tempNum++;                                                                                                              
	$$.code = $1.code + $3.code + ". " + $$.place + "\n" + "- " + $$.place + ", " + $1.place + ", " + $3.place + "\n";     
	}
	;
multiplicativeExpression: term
        {$$.place = $1.place; $$.code = "";}
        | term MOD multiplicativeExpression
        { $$.place = "temp_" + to_string(tempNum);
        tempNum++;                                                                                                              
	$$.code = $1.code + $3.code + ". " + $$.place + "\n" + "% " + $$.place + ", " + $1.place + ", " + $3.place + "\n";
	}
	| term DIV multiplicativeExpression 
        { $$.place = "temp_" + to_string(tempNum);
        tempNum++;                                                                                                              
	$$.code = $1.code + $3.code + ". " + $$.place + "\n" + "/ " + $$.place + ", " + $1.place + ", " + $3.place + "\n";}
	| term MULT multiplicativeExpression 
	{ $$.place = "temp_" + to_string(tempNum);
        tempNum++;
	$$.code = $1.code + $3.code + ". " + $$.place + "\n" + "* " + $$.place + ", " + $1.place + ", " + $3.place + "\n";}
	;
term: var
	{ 
	$$.place = $1.place; $$.code = $1.code;
        }
	| SUB var %prec UMINUS
        {$$.place = $2.place; $$.code = $2.code + "- " + $2.place + ", 0, " + $2.place + "\n";}
        | NUMBER
        {$$.place = to_string($1); $$.code = "";}
        | SUB NUMBER %prec UMINUS 
        {$$.place = "-" + to_string($2); $$.code = "";}
        | L_PAREN expression R_PAREN
        {$$.code = $2.code + "= " + $$.place + ", " + $2.place + "\n"; $$.place = $2.place;}
        | SUB L_PAREN expression R_PAREN %prec UMINUS
        {
	$$.code = $3.code;
	$$.code += "= " + $$.place + ", " + $3.place + "\n"; 
	$$.code += "- " + $$.place + ", 0, " + $$.place + "\n";
	$$.place = $3.place;
	}
        | IDENT L_PAREN expressionzWcomma R_PAREN
	{
	$$.place = "temp_" + to_string(tempNum);//this is a function so this is wrong
	tempNum++;
	$$.code = $3.code 
		+ ". " + $$.place 
				+ "\n" + "call " + $1 + ", " + $$.place;//3.place makes no sence
	}
	;
varzWcomma: var COMMA varzWcomma
	| var
	;
var: IDENT
	{$$.place = $1;}
	| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET
	{
	$$.place = "temp_" + to_string(tempNum);
	tempNum++;
	$$.code = ". " + $$.place + "\n" + "=[] " + $$.place + ", " + $1 + ", " + $3.place + "\n";}
	;


%%

   int main(int argc, char *argv[])
{
	yy::parser p; 
   return p.parse();
}

void yy::parser::error(const yy::location& l, const std::string& m)
{
	  no_error = false;
        cout << "Error in column " + to_string(col_c) + " row " + to_string(row_c) + " : " + m + "\n";
}

void myerror(string msg){
	no_error = false;
	cout << "Error in column " + to_string(col_c) + " row " + to_string(row_c) + " : " + msg + "\n";

}



