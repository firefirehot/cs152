// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.
#line 1 "part2text.y" // lalr1.cc:404


#line 39 "parser.tab.c" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.h"

// User implementation prologue.

#line 53 "parser.tab.c" // lalr1.cc:412
// Unqualified %code blocks.
#line 44 "part2text.y" // lalr1.cc:413


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

#line 85 "parser.tab.c" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 171 "parser.tab.c" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 56: // declarationsWsemi
      case 57: // declaration
        value.move< dec_str > (that.value);
        break;

      case 59: // statementzWsemi
      case 60: // statement
      case 61: // boolExpression
      case 62: // relationAndExpression
      case 63: // relationExpression
      case 69: // expression
      case 70: // multiplicativeExpression
      case 71: // term
        value.move< exp_str > (that.value);
        break;

      case 42: // NUMBER
        value.move< int > (that.value);
        break;

      case 58: // idents
        value.move< list<string> > (that.value);
        break;

      case 41: // IDENT
      case 54: // program
      case 55: // function
      case 64: // st
      case 66: // comp
        value.move< string > (that.value);
        break;

      case 67: // expressionzWcomma
      case 68: // expressionCommaChain
      case 72: // varzWcomma
      case 73: // var
        value.move< varz_str > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 56: // declarationsWsemi
      case 57: // declaration
        value.copy< dec_str > (that.value);
        break;

      case 59: // statementzWsemi
      case 60: // statement
      case 61: // boolExpression
      case 62: // relationAndExpression
      case 63: // relationExpression
      case 69: // expression
      case 70: // multiplicativeExpression
      case 71: // term
        value.copy< exp_str > (that.value);
        break;

      case 42: // NUMBER
        value.copy< int > (that.value);
        break;

      case 58: // idents
        value.copy< list<string> > (that.value);
        break;

      case 41: // IDENT
      case 54: // program
      case 55: // function
      case 64: // st
      case 66: // comp
        value.copy< string > (that.value);
        break;

      case 67: // expressionzWcomma
      case 68: // expressionCommaChain
      case 72: // varzWcomma
      case 73: // var
        value.copy< varz_str > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 56: // declarationsWsemi
      case 57: // declaration
        yylhs.value.build< dec_str > ();
        break;

      case 59: // statementzWsemi
      case 60: // statement
      case 61: // boolExpression
      case 62: // relationAndExpression
      case 63: // relationExpression
      case 69: // expression
      case 70: // multiplicativeExpression
      case 71: // term
        yylhs.value.build< exp_str > ();
        break;

      case 42: // NUMBER
        yylhs.value.build< int > ();
        break;

      case 58: // idents
        yylhs.value.build< list<string> > ();
        break;

      case 41: // IDENT
      case 54: // program
      case 55: // function
      case 64: // st
      case 66: // comp
        yylhs.value.build< string > ();
        break;

      case 67: // expressionzWcomma
      case 68: // expressionCommaChain
      case 72: // varzWcomma
      case 73: // var
        yylhs.value.build< varz_str > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 97 "part2text.y" // lalr1.cc:859
    {
	if(varTable.find("main") == varTable.end()){
	myerror("main function not found.");
	}
	for(list<func_str>::iterator it = checkTable.begin(); it != checkTable.end();it++){
	if(varTable.find(it->name) == varTable.end()){
	myerrorRC("Function call not found", it->row,it->col);
	}
	
	}
	if(no_error) cout << yystack_[0].value.as< string > () << endl;
	}
#line 672 "parser.tab.c" // lalr1.cc:859
    break;

  case 3:
#line 112 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "";}
#line 678 "parser.tab.c" // lalr1.cc:859
    break;

  case 4:
#line 114 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = yystack_[1].value.as< string > () + "\n" + yystack_[0].value.as< string > ();}
#line 684 "parser.tab.c" // lalr1.cc:859
    break;

  case 5:
#line 117 "part2text.y" // lalr1.cc:859
    {
	bool triggered = false;
	for(std::map<string,int>::iterator it = varTable.begin(); it != varTable.end(); it++){//pushes all the varibles in the var table into the super table for error checking
	superTable.push_back(it->first);
	if(it->first == yystack_[10].value.as< string > ()){myerror("Variable named after function.");} //checks if any current variables used the same name of the past functions
	}
	yylhs.value.as< string > () = "func " + yystack_[10].value.as< string > () + "\n";
	for(list<string>::iterator it = superTable.begin(); it != superTable.end();it++){ //checks if any past variables used the name of the current function
	if(*it == yystack_[10].value.as< string > ()){triggered = true;}
	}
	if(triggered){ //error is thrown here from function above to prevent multible errors from being thrown at the same mistake
        myerror("Variable named after function.");
        }
	varTable.insert(make_pair(yystack_[10].value.as< string > (),2)); //inserts function name into var table so that future varibles can't use the name
	yylhs.value.as< string > () += yystack_[7].value.as< dec_str > ().code;
	for (list<string>::iterator it = yystack_[7].value.as< dec_str > ().l.begin(); it != yystack_[7].value.as< dec_str > ().l.end(); it++){ 
	yylhs.value.as< string > () += "= " + *it + ", " + "$" + to_string(paramNum) + "\n";
	paramNum++;
	} 
	yylhs.value.as< string > () += yystack_[4].value.as< dec_str > ().code;
	yylhs.value.as< string > () += yystack_[1].value.as< exp_str > ().code;
	yylhs.value.as< string > () += "endfunc \n";
	for(std::map<string,int>::iterator it = varTable.begin(); it != varTable.end(); it++){//erases all NON-function symbols from the var table.
	if(it->second != 2){                                                                                                                                                                                         varTable.erase(it);                                                                                                                                                                          }                                                                                                                                                                                                    }
	}
#line 714 "parser.tab.c" // lalr1.cc:859
    break;

  case 6:
#line 143 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "";}
#line 720 "parser.tab.c" // lalr1.cc:859
    break;

  case 7:
#line 146 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< dec_str > ().code = "";yylhs.value.as< dec_str > ().l = list<string>();}
#line 726 "parser.tab.c" // lalr1.cc:859
    break;

  case 8:
#line 148 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< dec_str > ().code = yystack_[2].value.as< dec_str > ().code + yystack_[0].value.as< dec_str > ().code;
	yylhs.value.as< dec_str > ().l = yystack_[2].value.as< dec_str > ().l;
	for(list<string>::iterator it = yystack_[0].value.as< dec_str > ().l.begin(); it != yystack_[0].value.as< dec_str > ().l.end(); it++){
	yylhs.value.as< dec_str > ().l.push_back(*it);
	}
	}
#line 738 "parser.tab.c" // lalr1.cc:859
    break;

  case 9:
#line 156 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< dec_str > ().code = "";}
#line 744 "parser.tab.c" // lalr1.cc:859
    break;

  case 11:
#line 160 "part2text.y" // lalr1.cc:859
    {
	for(list<string>::iterator it = yystack_[7].value.as< list<string> > ().begin(); it != yystack_[7].value.as< list<string> > ().end(); it++){
	yylhs.value.as< dec_str > ().code += "[] " + *it + ", " + to_string(yystack_[3].value.as< int > ()) + "\n";
	yylhs.value.as< dec_str > ().l.push_back(*it);
	if(yystack_[3].value.as< int > () <= 0) {
	myerror("Created array with size less than or equal to zero.");
	}
	if (!varTable.insert(make_pair(*it,1)).second){
        myerror("Name already existed.");
        }
	} 
	}
#line 761 "parser.tab.c" // lalr1.cc:859
    break;

  case 12:
#line 173 "part2text.y" // lalr1.cc:859
    {
	for(list<string>::iterator it = yystack_[2].value.as< list<string> > ().begin(); it != yystack_[2].value.as< list<string> > ().end(); it++){
	yylhs.value.as< dec_str > ().code = ". " + *it + "\n";
	yylhs.value.as< dec_str > ().l.push_back(*it);
	if (!varTable.insert(make_pair(*it,0)).second){
        myerror("Name already existed.");
        }
	}
	}
#line 775 "parser.tab.c" // lalr1.cc:859
    break;

  case 13:
#line 184 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< list<string> > ().push_back(yystack_[2].value.as< string > ());
	for(list<string>::iterator it = yystack_[0].value.as< list<string> > ().begin(); it != yystack_[0].value.as< list<string> > ().end(); it++){
	yylhs.value.as< list<string> > ().push_back(*it);
	}
	}
#line 786 "parser.tab.c" // lalr1.cc:859
    break;

  case 14:
#line 191 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< list<string> > ().push_back(yystack_[0].value.as< string > ());
	}
#line 794 "parser.tab.c" // lalr1.cc:859
    break;

  case 15:
#line 196 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code; }
#line 801 "parser.tab.c" // lalr1.cc:859
    break;

  case 16:
#line 199 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = yystack_[1].value.as< exp_str > ().code;}
#line 807 "parser.tab.c" // lalr1.cc:859
    break;

  case 17:
#line 201 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = "";}
#line 813 "parser.tab.c" // lalr1.cc:859
    break;

  case 18:
#line 203 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = "";}
#line 819 "parser.tab.c" // lalr1.cc:859
    break;

  case 19:
#line 206 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = yystack_[0].value.as< exp_str > ().code + yystack_[2].value.as< varz_str > ().base.code + "= " + yystack_[2].value.as< varz_str > ().base.place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";}
#line 825 "parser.tab.c" // lalr1.cc:859
    break;

  case 20:
#line 208 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().begin = "label_" + to_string(labelNum);
	labelNum++;
	yylhs.value.as< exp_str > ().after = "label_" + to_string(labelNum);
	labelNum++;
	yylhs.value.as< exp_str > ().code = ": " + yylhs.value.as< exp_str > ().begin + "\n";
	yylhs.value.as< exp_str > ().code += yystack_[5].value.as< exp_str > ().code;
	yylhs.value.as< exp_str > ().code += "! " + yystack_[5].value.as< exp_str > ().place + ", " + yystack_[5].value.as< exp_str > ().place + "\n";
	yylhs.value.as< exp_str > ().code += "?:= " + yylhs.value.as< exp_str > ().after + ", " + yystack_[5].value.as< exp_str > ().place + "\n";
	yylhs.value.as< exp_str > ().code += yystack_[2].value.as< exp_str > ().code;
	yylhs.value.as< exp_str > ().code += ": " + yylhs.value.as< exp_str > ().after + "\n";
	}
#line 842 "parser.tab.c" // lalr1.cc:859
    break;

  case 21:
#line 221 "part2text.y" // lalr1.cc:859
    {
	 yylhs.value.as< exp_str > ().begin = "label_" + to_string(labelNum);
        labelNum++;
        yylhs.value.as< exp_str > ().after = "label_" + to_string(labelNum);
        labelNum++;
	string tempexp = "label_" + to_string(labelNum);
	labelNum++;
        yylhs.value.as< exp_str > ().code = ": " + yylhs.value.as< exp_str > ().begin + "\n";
        yylhs.value.as< exp_str > ().code += yystack_[7].value.as< exp_str > ().code;
        yylhs.value.as< exp_str > ().code += "! " + yystack_[7].value.as< exp_str > ().place + ", " + yystack_[7].value.as< exp_str > ().place + "\n"; 
        yylhs.value.as< exp_str > ().code += "?:= " + yystack_[2].value.as< exp_str > ().begin + ", " + yystack_[7].value.as< exp_str > ().place + "\n";
        yylhs.value.as< exp_str > ().code += yystack_[4].value.as< exp_str > ().code;
	yylhs.value.as< exp_str > ().code += ":= " + yylhs.value.as< exp_str > ().after + "\n";
	yylhs.value.as< exp_str > ().code += ": " + tempexp + "\n";
	yylhs.value.as< exp_str > ().code += yystack_[2].value.as< exp_str > ().code;
        yylhs.value.as< exp_str > ().code += ": " + yylhs.value.as< exp_str > ().after + "\n";
	}
#line 864 "parser.tab.c" // lalr1.cc:859
    break;

  case 22:
#line 239 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().begin = "label_" + to_string(labelNum);
        labelNum++;
        yylhs.value.as< exp_str > ().after = "label_" + to_string(labelNum);
        labelNum++;
	yylhs.value.as< exp_str > ().code = ": " + yylhs.value.as< exp_str > ().begin + "\n";
	
	yylhs.value.as< exp_str > ().code += yystack_[5].value.as< exp_str > ().code;
        yylhs.value.as< exp_str > ().code += "! " + yystack_[5].value.as< exp_str > ().place + ", " + yystack_[5].value.as< exp_str > ().place + "\n";
        yylhs.value.as< exp_str > ().code += "?:= " + yylhs.value.as< exp_str > ().after + ", " + yystack_[5].value.as< exp_str > ().place + "\n";
	yylhs.value.as< exp_str > ().code += yystack_[2].value.as< exp_str > ().code;
	yylhs.value.as< exp_str > ().code += ":= " + yylhs.value.as< exp_str > ().begin + "\n";
	
	yylhs.value.as< exp_str > ().code += ": " + yylhs.value.as< exp_str > ().after + "\n";
	}
#line 883 "parser.tab.c" // lalr1.cc:859
    break;

  case 23:
#line 254 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().begin = "label_" + to_string(labelNum);
        labelNum++;
        yylhs.value.as< exp_str > ().after = "label_" + to_string(labelNum);
        labelNum++;
	yylhs.value.as< exp_str > ().code = ": " + yylhs.value.as< exp_str > ().begin + "\n";

	yylhs.value.as< exp_str > ().code += yystack_[4].value.as< exp_str > ().code;
	yylhs.value.as< exp_str > ().code += yystack_[0].value.as< exp_str > ().code;
        yylhs.value.as< exp_str > ().code += "?:= " + yylhs.value.as< exp_str > ().begin + ", " + yystack_[0].value.as< exp_str > ().place + "\n";	

	yylhs.value.as< exp_str > ().code += ": " + yylhs.value.as< exp_str > ().after + "\n";
	}
#line 900 "parser.tab.c" // lalr1.cc:859
    break;

  case 24:
#line 267 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().code = "";
	list<string>::iterator ids = yystack_[0].value.as< varz_str > ().id.begin();
	for(list<string>::iterator it = yystack_[0].value.as< varz_str > ().addOn.begin(); it != yystack_[0].value.as< varz_str > ().addOn.end(); it++)
	{
		if(*ids == "__")
		{
			yylhs.value.as< exp_str > ().code += ".< " + *it + "\n";
		}else
		{
			yylhs.value.as< exp_str > ().code += ".[]< " + *it + ", " + *ids + "\n";
		}
		ids++;
	}
	
	}
#line 921 "parser.tab.c" // lalr1.cc:859
    break;

  case 25:
#line 284 "part2text.y" // lalr1.cc:859
    {
	
	 yylhs.value.as< exp_str > ().code = "";
	 list<string>::iterator ids = yystack_[0].value.as< varz_str > ().id.begin();
	 for(list<string>::iterator it = yystack_[0].value.as< varz_str > ().addOn.begin(); it != yystack_[0].value.as< varz_str > ().addOn.end(); it++)
         {
		if(*ids == "__")
		{
                        yylhs.value.as< exp_str > ().code += ".> " + *it + "\n";
                }else
                {
                        yylhs.value.as< exp_str > ().code += ".[]> " + *it + ", " + *ids + "\n";
                }
                ids++;
        }
	
	
	}
#line 944 "parser.tab.c" // lalr1.cc:859
    break;

  case 26:
#line 303 "part2text.y" // lalr1.cc:859
    {
	if(continueActive){
	yylhs.value.as< exp_str > ().code = ":= " + labelSave + "\n";
	}
	else{myerror("Continue outside loop.");}
	}
#line 955 "parser.tab.c" // lalr1.cc:859
    break;

  case 27:
#line 310 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = yystack_[0].value.as< exp_str > ().code + "ret " + yystack_[0].value.as< exp_str > ().place + "\n";}
#line 961 "parser.tab.c" // lalr1.cc:859
    break;

  case 28:
#line 313 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().code = yystack_[0].value.as< exp_str > ().code; yylhs.value.as< exp_str > ().place = yystack_[0].value.as< exp_str > ().place;}
#line 968 "parser.tab.c" // lalr1.cc:859
    break;

  case 29:
#line 316 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;
        yylhs.value.as< exp_str > ().code =  yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "|| " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";
	}
#line 978 "parser.tab.c" // lalr1.cc:859
    break;

  case 30:
#line 323 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = yystack_[0].value.as< exp_str > ().code; yylhs.value.as< exp_str > ().place = yystack_[0].value.as< exp_str > ().place;}
#line 984 "parser.tab.c" // lalr1.cc:859
    break;

  case 31:
#line 325 "part2text.y" // lalr1.cc:859
    {            
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;
        yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "&& " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";
	}
#line 994 "parser.tab.c" // lalr1.cc:859
    break;

  case 32:
#line 332 "part2text.y" // lalr1.cc:859
    {                                                          
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;
        yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + yystack_[1].value.as< string > () + " " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";
        }
#line 1004 "parser.tab.c" // lalr1.cc:859
    break;

  case 33:
#line 338 "part2text.y" // lalr1.cc:859
    {                                                                                    
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;
        yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + "! " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + "\n" + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + yystack_[1].value.as< string > () +" " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";
	}
#line 1014 "parser.tab.c" // lalr1.cc:859
    break;

  case 34:
#line 344 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = ""; yylhs.value.as< exp_str > ().place = "1";}
#line 1020 "parser.tab.c" // lalr1.cc:859
    break;

  case 35:
#line 346 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = ""; yylhs.value.as< exp_str > ().place = "0";}
#line 1026 "parser.tab.c" // lalr1.cc:859
    break;

  case 36:
#line 348 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = ""; yylhs.value.as< exp_str > ().place = "0";}
#line 1032 "parser.tab.c" // lalr1.cc:859
    break;

  case 37:
#line 350 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = ""; yylhs.value.as< exp_str > ().place = "1";}
#line 1038 "parser.tab.c" // lalr1.cc:859
    break;

  case 38:
#line 352 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().code = yystack_[1].value.as< exp_str > ().code /*+ "= " + $$.place + ", " + $2.place + "\n"*/;
	yylhs.value.as< exp_str > ().place = yystack_[1].value.as< exp_str > ().place;
	}
#line 1047 "parser.tab.c" // lalr1.cc:859
    break;

  case 39:
#line 357 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().code = yystack_[1].value.as< exp_str > ().place + "! " + yystack_[1].value.as< exp_str > ().place + ", " + yystack_[1].value.as< exp_str > ().place + "\n" /*+ "= " + $$.place + ", " + $3.place + "\n"*/;
        yylhs.value.as< exp_str > ().place = yystack_[1].value.as< exp_str > ().place;
	}
#line 1056 "parser.tab.c" // lalr1.cc:859
    break;

  case 40:
#line 364 "part2text.y" // lalr1.cc:859
    {continueActive = true; labelSave = "label_" + to_string(labelNum); yylhs.value.as< string > () = labelSave;labelNum++;}
#line 1062 "parser.tab.c" // lalr1.cc:859
    break;

  case 41:
#line 367 "part2text.y" // lalr1.cc:859
    {continueActive = false;}
#line 1068 "parser.tab.c" // lalr1.cc:859
    break;

  case 42:
#line 371 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "==";}
#line 1074 "parser.tab.c" // lalr1.cc:859
    break;

  case 43:
#line 373 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "!=";}
#line 1080 "parser.tab.c" // lalr1.cc:859
    break;

  case 44:
#line 375 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "<";}
#line 1086 "parser.tab.c" // lalr1.cc:859
    break;

  case 45:
#line 377 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = ">";}
#line 1092 "parser.tab.c" // lalr1.cc:859
    break;

  case 46:
#line 379 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "<=";}
#line 1098 "parser.tab.c" // lalr1.cc:859
    break;

  case 47:
#line 381 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = ">=";}
#line 1104 "parser.tab.c" // lalr1.cc:859
    break;

  case 48:
#line 384 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< varz_str > ().base.code = ""; yylhs.value.as< varz_str > ().addOn = list<string>();}
#line 1110 "parser.tab.c" // lalr1.cc:859
    break;

  case 49:
#line 386 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< varz_str > ().base.code = yystack_[0].value.as< exp_str > ().code;yylhs.value.as< varz_str > ().addOn.push_back(yystack_[0].value.as< exp_str > ().place);}
#line 1116 "parser.tab.c" // lalr1.cc:859
    break;

  case 50:
#line 388 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< varz_str > ().base.code = yystack_[1].value.as< exp_str > ().code + yystack_[0].value.as< varz_str > ().base.code;
	yylhs.value.as< varz_str > ().addOn.push_back(yystack_[1].value.as< exp_str > ().place);
	for(list<string>::iterator it = yystack_[0].value.as< varz_str > ().addOn.begin(); it != yystack_[0].value.as< varz_str > ().addOn.end(); it++){
	yylhs.value.as< varz_str > ().addOn.push_back(*it);
	}
	}
#line 1128 "parser.tab.c" // lalr1.cc:859
    break;

  case 51:
#line 397 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< varz_str > ().base.code = yystack_[1].value.as< exp_str > ().code + yystack_[0].value.as< varz_str > ().base.code;
	yylhs.value.as< varz_str > ().addOn.push_back(yystack_[1].value.as< exp_str > ().place);
	for(list<string>::iterator it = yystack_[0].value.as< varz_str > ().addOn.begin(); it != yystack_[0].value.as< varz_str > ().addOn.end(); it++){
	yylhs.value.as< varz_str > ().addOn.push_back(*it);  
	}
	}
#line 1140 "parser.tab.c" // lalr1.cc:859
    break;

  case 52:
#line 405 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< varz_str > ().addOn.push_back(yystack_[0].value.as< exp_str > ().place);
	yylhs.value.as< varz_str > ().base.code = yystack_[0].value.as< exp_str > ().code;
	
	}
#line 1150 "parser.tab.c" // lalr1.cc:859
    break;

  case 53:
#line 412 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = yystack_[0].value.as< exp_str > ().code; yylhs.value.as< exp_str > ().place = yystack_[0].value.as< exp_str > ().place; yylhs.value.as< exp_str > ().notLessThanZero = yystack_[0].value.as< exp_str > ().notLessThanZero;}
#line 1156 "parser.tab.c" // lalr1.cc:859
    break;

  case 54:
#line 414 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
	tempNum++;
	yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "+ " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";
	 }
#line 1166 "parser.tab.c" // lalr1.cc:859
    break;

  case 55:
#line 420 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;                                                                                                              
	yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "- " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";     
	}
#line 1176 "parser.tab.c" // lalr1.cc:859
    break;

  case 56:
#line 427 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().place = yystack_[0].value.as< exp_str > ().place; yylhs.value.as< exp_str > ().code = yystack_[0].value.as< exp_str > ().code; yylhs.value.as< exp_str > ().notLessThanZero = yystack_[0].value.as< exp_str > ().notLessThanZero;}
#line 1182 "parser.tab.c" // lalr1.cc:859
    break;

  case 57:
#line 429 "part2text.y" // lalr1.cc:859
    { yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;                                                                                                              
	yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "% " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";
	}
#line 1191 "parser.tab.c" // lalr1.cc:859
    break;

  case 58:
#line 434 "part2text.y" // lalr1.cc:859
    { yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;                                                                                                              
	yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "/ " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";}
#line 1199 "parser.tab.c" // lalr1.cc:859
    break;

  case 59:
#line 438 "part2text.y" // lalr1.cc:859
    { yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;
	yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "* " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";}
#line 1207 "parser.tab.c" // lalr1.cc:859
    break;

  case 60:
#line 443 "part2text.y" // lalr1.cc:859
    { 
	yylhs.value.as< exp_str > ().place = yystack_[0].value.as< varz_str > ().base.place; yylhs.value.as< exp_str > ().code = yystack_[0].value.as< varz_str > ().base.code;
        }
#line 1215 "parser.tab.c" // lalr1.cc:859
    break;

  case 61:
#line 447 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().place = yystack_[0].value.as< varz_str > ().base.place; yylhs.value.as< exp_str > ().code = yystack_[0].value.as< varz_str > ().base.code + "- " + yystack_[0].value.as< varz_str > ().base.place + ", 0, " + yystack_[0].value.as< varz_str > ().base.place + "\n";}
#line 1221 "parser.tab.c" // lalr1.cc:859
    break;

  case 62:
#line 449 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().place = to_string(yystack_[0].value.as< int > ()); yylhs.value.as< exp_str > ().code = "";}
#line 1227 "parser.tab.c" // lalr1.cc:859
    break;

  case 63:
#line 451 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().place = "-" + to_string(yystack_[0].value.as< int > ()); yylhs.value.as< exp_str > ().code = "";yylhs.value.as< exp_str > ().notLessThanZero = false;}
#line 1233 "parser.tab.c" // lalr1.cc:859
    break;

  case 64:
#line 453 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = yystack_[1].value.as< exp_str > ().code + "= " + yylhs.value.as< exp_str > ().place + ", " + yystack_[1].value.as< exp_str > ().place + "\n"; yylhs.value.as< exp_str > ().place = yystack_[1].value.as< exp_str > ().place;}
#line 1239 "parser.tab.c" // lalr1.cc:859
    break;

  case 65:
#line 455 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().code = yystack_[1].value.as< exp_str > ().code;
	yylhs.value.as< exp_str > ().code += "= " + yylhs.value.as< exp_str > ().place + ", " + yystack_[1].value.as< exp_str > ().place + "\n"; 
	yylhs.value.as< exp_str > ().code += "- " + yylhs.value.as< exp_str > ().place + ", 0, " + yylhs.value.as< exp_str > ().place + "\n";
	yylhs.value.as< exp_str > ().place = yystack_[1].value.as< exp_str > ().place;
	}
#line 1250 "parser.tab.c" // lalr1.cc:859
    break;

  case 66:
#line 462 "part2text.y" // lalr1.cc:859
    {
	
	func_str funTemp;//we save the current name, row and column of this ident so that we can check that the function call is good.
	funTemp.name = yystack_[3].value.as< string > ();
	funTemp.row = row_c;
	funTemp.col = col_c;
	checkTable.push_back(funTemp);
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
	tempNum++;
	yylhs.value.as< exp_str > ().code = yystack_[1].value.as< varz_str > ().base.code;
	for(list<string>::iterator it = yystack_[1].value.as< varz_str > ().addOn.begin(); it != yystack_[1].value.as< varz_str > ().addOn.end();it++){
	yylhs.value.as< exp_str > ().code += "param " + *it + "\n";
	}  
	yylhs.value.as< exp_str > ().code	+= ". " + yylhs.value.as< exp_str > ().place + "\n" + "call " + yystack_[3].value.as< string > () + ", " + yylhs.value.as< exp_str > ().place + "\n";
	}
#line 1270 "parser.tab.c" // lalr1.cc:859
    break;

  case 67:
#line 479 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< varz_str > ().addOn = yystack_[2].value.as< varz_str > ().addOn;
	yylhs.value.as< varz_str > ().id = yystack_[2].value.as< varz_str > ().id;
	for(list<string>::iterator it = yystack_[0].value.as< varz_str > ().id.begin(); it != yystack_[0].value.as< varz_str > ().id.end(); it++){
        yylhs.value.as< varz_str > ().id.push_back(*it);
        }
	for(list<string>::iterator it = yystack_[0].value.as< varz_str > ().addOn.begin(); it != yystack_[0].value.as< varz_str > ().addOn.end(); it++){ 
	yylhs.value.as< varz_str > ().addOn.push_back(*it);
	}
	
	}
#line 1286 "parser.tab.c" // lalr1.cc:859
    break;

  case 68:
#line 491 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< varz_str > ().addOn = yystack_[0].value.as< varz_str > ().addOn; yylhs.value.as< varz_str > ().id = yystack_[0].value.as< varz_str > ().id;}
#line 1292 "parser.tab.c" // lalr1.cc:859
    break;

  case 69:
#line 494 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< varz_str > ().base.place = yystack_[0].value.as< string > ();yylhs.value.as< varz_str > ().addOn.push_back(yystack_[0].value.as< string > ());yylhs.value.as< varz_str > ().id.push_back("__"); 
	if(varTable.find(yystack_[0].value.as< string > ()) == varTable.end())
	{
	myerror("undeclared variable.");
	}
	else if(varTable.find(yystack_[0].value.as< string > ())->second != 0){
	myerror("Used array name as a variable name.");
	}
	}
#line 1307 "parser.tab.c" // lalr1.cc:859
    break;

  case 70:
#line 505 "part2text.y" // lalr1.cc:859
    {
	if(yystack_[1].value.as< exp_str > ().notLessThanZero == false){
	myerror("attempted to access array with value less than or equal to zero.");
	}
	yylhs.value.as< varz_str > ().base.place = "temp_" + to_string(tempNum);
	tempNum++;
	yylhs.value.as< varz_str > ().base.code = ". " + yylhs.value.as< varz_str > ().base.place + "\n" + "=[] " + yylhs.value.as< varz_str > ().base.place + ", " + yystack_[3].value.as< string > () + ", " + yystack_[1].value.as< exp_str > ().place + "\n";
	yylhs.value.as< varz_str > ().addOn.push_back(yystack_[3].value.as< string > ());
	yylhs.value.as< varz_str > ().id.push_back(yystack_[1].value.as< exp_str > ().place);
	if(varTable.find(yystack_[3].value.as< string > ()) == varTable.end())
	{
	myerror("undeclared array.");
	}
	else if(varTable.find(yystack_[3].value.as< string > ())->second != 1){
	myerror("Used variable name as an array name.");
	}
	}
#line 1329 "parser.tab.c" // lalr1.cc:859
    break;


#line 1333 "parser.tab.c" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -105;

  const signed char parser::yytable_ninf_ = -17;

  const short int
  parser::yypact_[] =
  {
      14,    11,     6,  -105,    14,  -105,   -19,  -105,  -105,    30,
       3,     8,    13,    44,     4,    26,  -105,    32,    61,    18,
      18,    70,  -105,    15,  -105,  -105,  -105,    37,    82,    50,
      97,    72,    65,   102,    80,    49,    49,   116,  -105,   104,
     104,   -15,    98,   138,    10,    99,   140,  -105,    92,  -105,
    -105,    23,     9,  -105,    49,   134,   126,   128,    63,   101,
     107,  -105,   135,  -105,  -105,   108,  -105,   -15,  -105,   -15,
    -105,  -105,    95,   -15,  -105,  -105,  -105,    49,    63,  -105,
     -15,  -105,   -15,   109,    90,  -105,    49,    49,  -105,  -105,
    -105,  -105,  -105,  -105,   -15,   -15,   -15,   -15,   -15,   -15,
    -105,    65,   104,   110,   106,  -105,  -105,   111,   -15,   112,
     113,   117,  -105,  -105,    65,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,    65,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,   -15,  -105,   145,  -105,   143,   117,    65,   149,   146,
     148,  -105,  -105,  -105,  -105,    49,   152,  -105,  -105
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,     0,     2,     3,     6,     0,     1,     4,     0,
       0,     0,    14,     0,     0,     0,     9,     0,     0,     0,
       0,     0,    13,     0,    10,     8,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,    69,     0,     0,     0,     0,    17,     0,    34,
      36,     0,    69,    62,     0,     0,    28,    30,     0,    53,
      56,    60,     0,    40,    24,    68,    25,     0,    27,     0,
       5,    18,     0,     0,    11,    35,    37,     0,     0,    63,
       0,    61,    48,     0,     0,    40,     0,     0,    42,    43,
      44,    45,    46,    47,     0,     0,     0,     0,     0,     0,
      40,     0,     0,     0,     0,    15,    19,     0,     0,     0,
       0,    49,    38,    64,     0,    29,    31,    32,    55,    54,
      59,    58,    57,     0,    41,    67,    70,    39,    33,    65,
      66,     0,    50,    41,    41,     0,    52,     0,     0,     0,
       0,    51,    41,    20,    22,     0,     0,    23,    21
  };

  const short int
  parser::yypgoto_[] =
  {
    -105,  -105,   164,  -105,    17,  -105,   153,   -69,  -105,   -36,
      84,  -105,   -72,  -104,    91,  -105,    36,   -34,    45,  -105,
     -39,   -30
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    13,    14,    15,    43,    44,    55,
      56,    57,   101,   135,    94,   110,   132,    58,    59,    60,
      64,    61
  };

  const short int
  parser::yytable_[] =
  {
      62,    66,    45,   105,    11,    19,     7,    68,    -7,    65,
      65,    71,     5,   114,    78,    51,    11,     1,    83,    11,
      84,    81,    -7,    -7,     9,    -7,    52,    53,   123,   138,
     139,    67,   124,   103,    10,   104,    24,    25,   146,   106,
      28,   107,    45,    84,    12,   133,   109,    20,   111,    18,
     115,    16,     6,    72,   134,    82,    12,    69,    17,    12,
     117,   118,   119,   125,    42,    79,    34,    23,   142,    80,
      21,    45,    65,    12,   128,    48,    49,    50,    35,    51,
      26,    27,    36,    37,    45,    29,    38,    39,    40,    30,
      52,    53,    31,    45,    41,    54,    34,   136,    88,    89,
      90,    91,    92,    93,   -16,    32,    42,    45,    35,   147,
     -16,   -16,    36,    37,    46,   -16,    38,    39,    40,    75,
      76,    33,    51,    47,    41,    88,    89,    90,    91,    92,
      93,    95,    96,    52,    53,    63,    42,   113,    77,    97,
      98,    99,   120,   121,   122,    42,    69,    70,    85,    73,
      74,    86,    87,   102,   100,   126,   112,   113,   127,   129,
     130,   137,   131,   140,   143,   145,   144,   148,     8,   108,
      22,   116,   141
  };

  const unsigned char
  parser::yycheck_[] =
  {
      36,    40,    32,    72,     1,     1,     0,    41,     5,    39,
      40,     1,     1,    85,    48,    30,     1,     3,    54,     1,
      54,    51,     7,     5,    43,     7,    41,    42,   100,   133,
     134,    46,   101,    67,     4,    69,    19,    20,   142,    73,
      23,    77,    72,    77,    41,   114,    80,    43,    82,     5,
      86,    43,    41,    43,   123,    46,    41,    48,    45,    41,
      94,    95,    96,   102,    41,    42,     1,     6,   137,    46,
      44,   101,   102,    41,   108,    26,    27,    28,    13,    30,
      10,    11,    17,    18,   114,    48,    21,    22,    23,     7,
      41,    42,    42,   123,    29,    46,     1,   131,    35,    36,
      37,    38,    39,    40,     9,     8,    41,   137,    13,   145,
      15,    16,    17,    18,    12,    20,    21,    22,    23,    27,
      28,    49,    30,    43,    29,    35,    36,    37,    38,    39,
      40,    30,    31,    41,    42,    19,    41,    47,    46,    32,
      33,    34,    97,    98,    99,    41,    48,     9,    14,    50,
      10,    25,    24,    45,    19,    49,    47,    47,    47,    47,
      47,    16,    45,    20,    15,    17,    20,    15,     4,    78,
      17,    87,   136
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    53,    54,    55,     1,    41,     0,    54,    43,
       4,     1,    41,    56,    57,    58,    43,    45,     5,     1,
      43,    44,    58,     6,    56,    56,    10,    11,    56,    48,
       7,    42,     8,    49,     1,    13,    17,    18,    21,    22,
      23,    29,    41,    59,    60,    73,    12,    43,    26,    27,
      28,    30,    41,    42,    46,    61,    62,    63,    69,    70,
      71,    73,    61,    19,    72,    73,    72,    46,    69,    48,
       9,     1,    43,    50,    10,    27,    28,    46,    69,    42,
      46,    73,    46,    61,    69,    14,    25,    24,    35,    36,
      37,    38,    39,    40,    66,    30,    31,    32,    33,    34,
      19,    64,    45,    69,    69,    59,    69,    61,    66,    69,
      67,    69,    47,    47,    64,    61,    62,    69,    69,    69,
      70,    70,    70,    64,    59,    72,    49,    47,    69,    47,
      47,    45,    68,    59,    59,    65,    69,    16,    65,    65,
      20,    68,    59,    15,    20,    17,    65,    61,    15
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    52,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    65,    66,    66,    66,    66,    66,    66,    67,    67,
      67,    68,    68,    69,    69,    69,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,    12,     2,     0,     3,     2,
       3,     8,     3,     3,     1,     3,     2,     2,     2,     3,
       7,     9,     7,     8,     2,     2,     1,     2,     1,     3,
       1,     3,     3,     4,     1,     2,     1,     2,     3,     4,
       0,     0,     1,     1,     1,     1,     1,     1,     0,     1,
       2,     3,     2,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     1,     2,     3,     4,     4,     3,     1,     1,
       4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS",
  "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY",
  "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO",
  "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT",
  "TRUE", "FALSE", "RETURN", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ",
  "NEQ", "LT", "GT", "LTE", "GTE", "IDENT", "NUMBER", "SEMICOLON", "COLON",
  "COMMA", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET",
  "ASSIGN", "UMINUS", "$accept", "prog_start", "program", "function",
  "declarationsWsemi", "declaration", "idents", "statementzWsemi",
  "statement", "boolExpression", "relationAndExpression",
  "relationExpression", "st", "en", "comp", "expressionzWcomma",
  "expressionCommaChain", "expression", "multiplicativeExpression", "term",
  "varzWcomma", "var", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,    96,    96,   112,   113,   116,   142,   146,   147,   155,
     157,   159,   172,   183,   190,   195,   198,   200,   202,   205,
     207,   220,   238,   253,   266,   283,   302,   309,   312,   315,
     322,   324,   331,   337,   343,   345,   347,   349,   351,   356,
     364,   367,   370,   372,   374,   376,   378,   380,   384,   385,
     387,   396,   404,   411,   413,   419,   426,   428,   433,   437,
     442,   446,   448,   450,   452,   454,   461,   478,   490,   493,
     504
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1808 "parser.tab.c" // lalr1.cc:1167
#line 525 "part2text.y" // lalr1.cc:1168


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

