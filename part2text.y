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
	bool notLessThanZero = true;
};
struct dec_str{
	string code;
	string id;
	list<string> l;
	};
struct varz_str{
	exp_str base;
	list<string> addOn;
	list<string> id;
};
struct func_str{
	string name;
	long row;
	long col;		
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
void myerrorRC(string msg, long r,long c);
string errorArray[30];
bool no_error = true;
long tempNum = 0;
long labelNum = 0;
long paramNum = 0;
map <string,int> varTable;
list<string> superTable;
bool continueActive = false;
string labelSave;
list<func_str> checkTable;
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
%type <string> program function comp st
%type<exp_str> expression multiplicativeExpression term boolExpression statement relationExpression relationAndExpression statementzWsemi
%type<varz_str> var varzWcomma expressionzWcomma expressionCommaChain
%type<dec_str> declarationsWsemi declaration
%type<list<string>> idents
%%

%start prog_start;

prog_start: program 
	{
	if(varTable.find("main") == varTable.end()){
	myerror("main function not found.");
	}
	for(list<func_str>::iterator it = checkTable.begin(); it != checkTable.end();it++){
	if(varTable.find(it->name) == varTable.end()){
	myerrorRC("Function call not found", it->row,it->col);
	}
	
	}
	if(no_error) cout << $1 << endl;
	}
	;

program:/*epsilon*/
	{$$ = "";} 
	| function program
	{$$ = $1 + "\n" + $2;}
	;
function: FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarationsWsemi END_PARAMS BEGIN_LOCALS declarationsWsemi END_LOCALS BEGIN_BODY statementzWsemi END_BODY
	{
	bool triggered = false;
	for(std::map<string,int>::iterator it = varTable.begin(); it != varTable.end(); it++){//pushes all the varibles in the var table into the super table for error checking
	superTable.push_back(it->first);
	if(it->first == $2){myerror("Variable named after function.");} //checks if any current variables used the same name of the past functions
	}
	$$ = "func " + $2 + "\n";
	for(list<string>::iterator it = superTable.begin(); it != superTable.end();it++){ //checks if any past variables used the name of the current function
	if(*it == $2){triggered = true;}
	}
	if(triggered){ //error is thrown here from function above to prevent multible errors from being thrown at the same mistake
        myerror("Variable named after function.");
        }
	varTable.insert(make_pair($2,2)); //inserts function name into var table so that future varibles can't use the name
	$$ += $5.code;
	for (list<string>::iterator it = $5.l.begin(); it != $5.l.end(); it++){ 
	$$ += "= " + *it + ", " + "$" + to_string(paramNum) + "\n";
	paramNum++;
	} 
	$$ += $8.code;
	$$ += $11.code;
	$$ += "endfunc \n";
	for(std::map<string,int>::iterator it = varTable.begin(); it != varTable.end(); it++){//erases all NON-function symbols from the var table.
	if(it->second != 2){                                                                                                                                                                                         varTable.erase(it);                                                                                                                                                                          }                                                                                                                                                                                                    }
	}
	| FUNCTION error
	{$$ = "";}
        ;
declarationsWsemi: /*epsilon*/
	{$$.code = "";$$.l = list<string>();}
        | declaration SEMICOLON declarationsWsemi
	{
	$$.code = $1.code + $3.code;
	$$.l = $1.l;
	for(list<string>::iterator it = $3.l.begin(); it != $3.l.end(); it++){
	$$.l.push_back(*it);
	}
	}
	| error SEMICOLON
	{$$.code = "";}
	| declaration error declarationsWsemi
        ;
declaration: idents COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
	{
	for(list<string>::iterator it = $1.begin(); it != $1.end(); it++){
	$$.code += "[] " + *it + ", " + to_string($5) + "\n";
	$$.l.push_back(*it);
	if($5 <= 0) {
	myerror("Created array with size less than or equal to zero.");
	}
	if (!varTable.insert(make_pair(*it,1)).second){
        myerror("Name already existed.");
        }
	} 
	}
	| idents COLON INTEGER
        {
	for(list<string>::iterator it = $1.begin(); it != $1.end(); it++){
	$$.code = ". " + *it + "\n";
	$$.l.push_back(*it);
	if (!varTable.insert(make_pair(*it,0)).second){
        myerror("Name already existed.");
        }
	}
	}
	;
idents: IDENT COMMA idents
	{
	$$.push_back($1);
	for(list<string>::iterator it = $3.begin(); it != $3.end(); it++){
	$$.push_back(*it);
	}
	}
	| IDENT
	{
	$$.push_back($1);
	}
        ;
statementzWsemi: statement SEMICOLON statementzWsemi
	{
	$$.code = $1.code + $3.code; } 
	| statement SEMICOLON
	{$$.code = $1.code;}
	| error SEMICOLON
	{$$.code = "";}
	| statement error
	{$$.code = "";}
	;
statement: var ASSIGN expression
        {$$.code = $3.code + $1.base.code + "= " + $1.base.place + ", " + $3.place + "\n";}
	| IF boolExpression THEN st statementzWsemi en ENDIF
	{
	$$.begin = "label_" + to_string(labelNum);
	labelNum++;
	$$.after = "label_" + to_string(labelNum);
	labelNum++;
	$$.code = ": " + $$.begin + "\n";
	$$.code += $2.code;
	$$.code += "! " + $2.place + ", " + $2.place + "\n";
	$$.code += "?:= " + $$.after + ", " + $2.place + "\n";
	$$.code += $5.code;
	$$.code += ": " + $$.after + "\n";
	}  
	| IF boolExpression THEN st statementzWsemi ELSE statementzWsemi en ENDIF
	{
	 $$.begin = "label_" + to_string(labelNum);
        labelNum++;
        $$.after = "label_" + to_string(labelNum);
        labelNum++;
	string tempexp = "label_" + to_string(labelNum);
	labelNum++;
        $$.code = ": " + $$.begin + "\n";
        $$.code += $2.code;
        $$.code += "! " + $2.place + ", " + $2.place + "\n"; 
        $$.code += "?:= " + $7.begin + ", " + $2.place + "\n";
        $$.code += $5.code;
	$$.code += ":= " + $$.after + "\n";
	$$.code += ": " + tempexp + "\n";
	$$.code += $7.code;
        $$.code += ": " + $$.after + "\n";
	}  
	| WHILE boolExpression BEGINLOOP st statementzWsemi en ENDLOOP
	{$$.begin = "label_" + to_string(labelNum);
        labelNum++;
        $$.after = "label_" + to_string(labelNum);
        labelNum++;
	$$.code = ": " + $$.begin + "\n";
	
	$$.code += $2.code;
        $$.code += "! " + $2.place + ", " + $2.place + "\n";
        $$.code += "?:= " + $$.after + ", " + $2.place + "\n";
	$$.code += $5.code;
	$$.code += ":= " + $$.begin + "\n";
	
	$$.code += ": " + $$.after + "\n";
	}  
        | DO BEGINLOOP st statementzWsemi en ENDLOOP WHILE boolExpression
	{$$.begin = "label_" + to_string(labelNum);
        labelNum++;
        $$.after = "label_" + to_string(labelNum);
        labelNum++;
	$$.code = ": " + $$.begin + "\n";

	$$.code += $4.code;
	$$.code += $8.code;
        $$.code += "?:= " + $$.begin + ", " + $8.place + "\n";	

	$$.code += ": " + $$.after + "\n";
	}  
        | READ varzWcomma
	{
	$$.code = "";
	list<string>::iterator ids = $2.id.begin();
	for(list<string>::iterator it = $2.addOn.begin(); it != $2.addOn.end(); it++)
	{
		if(*ids == "__")
		{
			$$.code += ".< " + *it + "\n";
		}else
		{
			$$.code += ".[]< " + *it + ", " + *ids + "\n";
		}
		ids++;
	}
	
	}  
        | WRITE varzWcomma 
	{
	
	 $$.code = "";
	 list<string>::iterator ids = $2.id.begin();
	 for(list<string>::iterator it = $2.addOn.begin(); it != $2.addOn.end(); it++)
         {
		if(*ids == "__")
		{
                        $$.code += ".> " + *it + "\n";
                }else
                {
                        $$.code += ".[]> " + *it + ", " + *ids + "\n";
                }
                ids++;
        }
	
	
	}
	| CONTINUE
	{
	if(continueActive){
	$$.code = ":= " + labelSave + "\n";
	}
	else{myerror("Continue outside loop.");}
	}  
	| RETURN expression
	{$$.code = $2.code + "ret " + $2.place + "\n";}  
        ;
boolExpression: relationAndExpression
        {
	$$.code = $1.code; $$.place = $1.place;}
	| relationAndExpression OR boolExpression
	{
	$$.place = "temp_" + to_string(tempNum);
        tempNum++;
        $$.code =  $1.code + $3.code + ". " + $$.place + "\n" + "|| " + $$.place + ", " + $1.place + ", " + $3.place + "\n";
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
	$$.code = $2.code /*+ "= " + $$.place + ", " + $2.place + "\n"*/;
	$$.place = $2.place;
	}
        |  NOT L_PAREN boolExpression R_PAREN
	{
	$$.code = $3.place + "! " + $3.place + ", " + $3.place + "\n" /*+ "= " + $$.place + ", " + $3.place + "\n"*/;
        $$.place = $3.place;
	} 
	;

st:/*epsilon*/
	{continueActive = true; labelSave = "label_" + to_string(labelNum); $$ = labelSave;labelNum++;}
	;
en:/*epsilon*/
	{continueActive = false;}
	;

comp: EQ
        {$$ = "==";}
        | NEQ
        {$$ = "!=";}
        | LT
        {$$ = "<";}
        | GT
        {$$ = ">";}
        | LTE
        {$$ = "<=";}
        | GTE
	{$$ = ">=";}
	;
expressionzWcomma:/*epsilon*/ 
	{$$.base.code = ""; $$.addOn = list<string>();}	
	| expression
	{$$.base.code = $1.code;$$.addOn.push_back($1.place);}
        |expression expressionCommaChain
	{
	$$.base.code = $1.code + $2.base.code;
	$$.addOn.push_back($1.place);
	for(list<string>::iterator it = $2.addOn.begin(); it != $2.addOn.end(); it++){
	$$.addOn.push_back(*it);
	}
	}
	;
expressionCommaChain: COMMA expression expressionCommaChain
	{
	$$.base.code = $2.code + $3.base.code;
	$$.addOn.push_back($2.place);
	for(list<string>::iterator it = $3.addOn.begin(); it != $3.addOn.end(); it++){
	$$.addOn.push_back(*it);  
	}
	}
	| COMMA expression
	{
	$$.addOn.push_back($2.place);
	$$.base.code = $2.code;
	
	}
	;
expression: multiplicativeExpression
        {$$.code = $1.code; $$.place = $1.place; $$.notLessThanZero = $1.notLessThanZero;}
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
        {$$.place = $1.place; $$.code = $1.code; $$.notLessThanZero = $1.notLessThanZero;}
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
	$$.place = $1.base.place; $$.code = $1.base.code;
        }
	| SUB var %prec UMINUS
        {$$.place = $2.base.place; $$.code = $2.base.code + "- " + $2.base.place + ", 0, " + $2.base.place + "\n";}
        | NUMBER
        {$$.place = to_string($1); $$.code = "";}
        | SUB NUMBER %prec UMINUS 
        {$$.place = "-" + to_string($2); $$.code = "";$$.notLessThanZero = false;}
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
	
	func_str funTemp;//we save the current name, row and column of this ident so that we can check that the function call is good.
	funTemp.name = $1;
	funTemp.row = row_c;
	funTemp.col = col_c;
	checkTable.push_back(funTemp);
	$$.place = "temp_" + to_string(tempNum);
	tempNum++;
	$$.code = $3.base.code;
	for(list<string>::iterator it = $3.addOn.begin(); it != $3.addOn.end();it++){
	$$.code += "param " + *it + "\n";
	}  
	$$.code	+= ". " + $$.place + "\n" + "call " + $1 + ", " + $$.place + "\n";
	}
	;
varzWcomma: var COMMA varzWcomma
	{
	$$.addOn = $1.addOn;
	$$.id = $1.id;
	for(list<string>::iterator it = $3.id.begin(); it != $3.id.end(); it++){
        $$.id.push_back(*it);
        }
	for(list<string>::iterator it = $3.addOn.begin(); it != $3.addOn.end(); it++){ 
	$$.addOn.push_back(*it);
	}
	
	}
	| var
	{$$.addOn = $1.addOn; $$.id = $1.id;}
	;
var: IDENT
	{
	$$.base.place = $1;$$.addOn.push_back($1);$$.id.push_back("__"); 
	if(varTable.find($1) == varTable.end())
	{
	myerror("undeclared variable.");
	}
	else if(varTable.find($1)->second != 0){
	myerror("Used array name as a variable name.");
	}
	}
	| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET
	{
	if($3.notLessThanZero == false){
	myerror("attempted to access array with value less than or equal to zero.");
	}
	$$.base.place = "temp_" + to_string(tempNum);
	tempNum++;
	$$.base.code = ". " + $$.base.place + "\n" + "=[] " + $$.base.place + ", " + $1 + ", " + $3.place + "\n";
	$$.addOn.push_back($1);
	$$.id.push_back($3.place);
	if(varTable.find($1) == varTable.end())
	{
	myerror("undeclared array.");
	}
	else if(varTable.find($1)->second != 1){
	myerror("Used variable name as an array name.");
	}
	}
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
        cout << "Error in row " + to_string(row_c) + " column " + to_string(col_c) + " : " + m + "\n";
}

void myerror(string msg){
	no_error = false;
	cout << "Error in row " + to_string(row_c) + " column " + to_string(col_c) + " : " + msg + "\n";

}

void myerrorRC(string msg, long r, long c){
        no_error = false;
        cout << "Error in row " + to_string(r) + " column " + to_string(c) + " : " + msg + "\n";

}

