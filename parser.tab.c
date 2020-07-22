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
#line 38 "part2text.y" // lalr1.cc:413


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
long paramNum = 0;
map <string,int> varTable;

#line 80 "parser.tab.c" // lalr1.cc:413


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
#line 166 "parser.tab.c" // lalr1.cc:479

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
      case 57: // declarationsWsemi
      case 58: // declaration
        value.move< dec_str > (that.value);
        break;

      case 60: // statementzWsemi
      case 61: // statement
      case 62: // boolExpression
      case 63: // relationAndExpression
      case 64: // relationExpression
      case 68: // expression
      case 69: // multiplicativeExpression
      case 70: // term
        value.move< exp_str > (that.value);
        break;

      case 42: // NUMBER
        value.move< int > (that.value);
        break;

      case 41: // IDENT
      case 54: // program
      case 55: // function
      case 59: // idents
      case 65: // comp
        value.move< string > (that.value);
        break;

      case 66: // expressionzWcomma
      case 67: // expressionCommaChain
      case 71: // varzWcomma
      case 72: // var
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
      case 57: // declarationsWsemi
      case 58: // declaration
        value.copy< dec_str > (that.value);
        break;

      case 60: // statementzWsemi
      case 61: // statement
      case 62: // boolExpression
      case 63: // relationAndExpression
      case 64: // relationExpression
      case 68: // expression
      case 69: // multiplicativeExpression
      case 70: // term
        value.copy< exp_str > (that.value);
        break;

      case 42: // NUMBER
        value.copy< int > (that.value);
        break;

      case 41: // IDENT
      case 54: // program
      case 55: // function
      case 59: // idents
      case 65: // comp
        value.copy< string > (that.value);
        break;

      case 66: // expressionzWcomma
      case 67: // expressionCommaChain
      case 71: // varzWcomma
      case 72: // var
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
      case 57: // declarationsWsemi
      case 58: // declaration
        yylhs.value.build< dec_str > ();
        break;

      case 60: // statementzWsemi
      case 61: // statement
      case 62: // boolExpression
      case 63: // relationAndExpression
      case 64: // relationExpression
      case 68: // expression
      case 69: // multiplicativeExpression
      case 70: // term
        yylhs.value.build< exp_str > ();
        break;

      case 42: // NUMBER
        yylhs.value.build< int > ();
        break;

      case 41: // IDENT
      case 54: // program
      case 55: // function
      case 59: // idents
      case 65: // comp
        yylhs.value.build< string > ();
        break;

      case 66: // expressionzWcomma
      case 67: // expressionCommaChain
      case 71: // varzWcomma
      case 72: // var
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
#line 84 "part2text.y" // lalr1.cc:859
    {if(no_error) cout << yystack_[0].value.as< string > () << endl;}
#line 644 "parser.tab.c" // lalr1.cc:859
    break;

  case 3:
#line 88 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "";}
#line 650 "parser.tab.c" // lalr1.cc:859
    break;

  case 4:
#line 90 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = yystack_[1].value.as< string > () + "\n" + yystack_[0].value.as< string > ();}
#line 656 "parser.tab.c" // lalr1.cc:859
    break;

  case 5:
#line 93 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "func " + yystack_[10].value.as< string > () + "\n";
	yylhs.value.as< string > () += yystack_[7].value.as< dec_str > ().code;
	for (list<string>::iterator it = yystack_[7].value.as< dec_str > ().l.begin(); it != yystack_[7].value.as< dec_str > ().l.end(); it++){
	yylhs.value.as< string > () += "= " + *it + ", " + "$" + to_string(paramNum) + "\n";
	paramNum++;
	} 
	yylhs.value.as< string > () += yystack_[4].value.as< dec_str > ().code;
	yylhs.value.as< string > () += yystack_[1].value.as< exp_str > ().code;
	yylhs.value.as< string > () += "endfunc \n";
	}
#line 671 "parser.tab.c" // lalr1.cc:859
    break;

  case 6:
#line 104 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "";}
#line 677 "parser.tab.c" // lalr1.cc:859
    break;

  case 7:
#line 107 "part2text.y" // lalr1.cc:859
    {	
	for(std::map<string,int>::iterator it = varTable.begin(); it != varTable.end(); it++){
	it->second = it->second - 1;	
	}
	}
#line 687 "parser.tab.c" // lalr1.cc:859
    break;

  case 8:
#line 113 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< dec_str > ().code = "";yylhs.value.as< dec_str > ().l = list<string>();}
#line 693 "parser.tab.c" // lalr1.cc:859
    break;

  case 9:
#line 115 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< dec_str > ().code = yystack_[2].value.as< dec_str > ().code + yystack_[0].value.as< dec_str > ().code;
	yylhs.value.as< dec_str > ().l = yystack_[2].value.as< dec_str > ().l;
	for(list<string>::iterator it = yystack_[0].value.as< dec_str > ().l.begin(); it != yystack_[0].value.as< dec_str > ().l.end(); it++){
	yylhs.value.as< dec_str > ().l.push_back(*it);
	}
	}
#line 705 "parser.tab.c" // lalr1.cc:859
    break;

  case 10:
#line 123 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< dec_str > ().code = "";}
#line 711 "parser.tab.c" // lalr1.cc:859
    break;

  case 12:
#line 127 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< dec_str > ().code = "'[]' " + yystack_[7].value.as< string > () + ", " + to_string(yystack_[3].value.as< int > ());}
#line 717 "parser.tab.c" // lalr1.cc:859
    break;

  case 13:
#line 129 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< dec_str > ().code = ". " + yystack_[2].value.as< string > () + "\n";
	yylhs.value.as< dec_str > ().l.push_back(yystack_[2].value.as< string > ());
	}
#line 726 "parser.tab.c" // lalr1.cc:859
    break;

  case 14:
#line 135 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = yystack_[2].value.as< string > () + yystack_[0].value.as< string > ();
	if (!varTable.insert(make_pair(yystack_[2].value.as< string > (),1)).second){
	myerror("Variable already existed.");
	}
	}
#line 736 "parser.tab.c" // lalr1.cc:859
    break;

  case 15:
#line 141 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = yystack_[0].value.as< string > ();
	if (!varTable.insert(make_pair(yystack_[0].value.as< string > (),1)).second){
	myerror("Variable already existed.");
	}
	}
#line 746 "parser.tab.c" // lalr1.cc:859
    break;

  case 16:
#line 148 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code; }
#line 753 "parser.tab.c" // lalr1.cc:859
    break;

  case 17:
#line 151 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = yystack_[1].value.as< exp_str > ().code;}
#line 759 "parser.tab.c" // lalr1.cc:859
    break;

  case 18:
#line 153 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = "";}
#line 765 "parser.tab.c" // lalr1.cc:859
    break;

  case 19:
#line 155 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = "";}
#line 771 "parser.tab.c" // lalr1.cc:859
    break;

  case 20:
#line 158 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = yystack_[0].value.as< exp_str > ().code + yystack_[2].value.as< varz_str > ().base.code + "= " + yystack_[2].value.as< varz_str > ().base.place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";}
#line 777 "parser.tab.c" // lalr1.cc:859
    break;

  case 21:
#line 160 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().begin = "label_" + to_string(labelNum);
	labelNum++;
	yylhs.value.as< exp_str > ().after = "label_" + to_string(labelNum);
	labelNum++;
	yylhs.value.as< exp_str > ().code = ": " + yylhs.value.as< exp_str > ().begin + "\n";
	yylhs.value.as< exp_str > ().code += yystack_[3].value.as< exp_str > ().code;
	yylhs.value.as< exp_str > ().code += "! " + yystack_[3].value.as< exp_str > ().place + ", " + yystack_[3].value.as< exp_str > ().place + "\n";
	yylhs.value.as< exp_str > ().code += "?:= " + yylhs.value.as< exp_str > ().after + ", " + yystack_[3].value.as< exp_str > ().place + "\n";
	yylhs.value.as< exp_str > ().code += yystack_[1].value.as< exp_str > ().code;
	yylhs.value.as< exp_str > ().code += ": " + yylhs.value.as< exp_str > ().after + "\n";
	}
#line 794 "parser.tab.c" // lalr1.cc:859
    break;

  case 22:
#line 173 "part2text.y" // lalr1.cc:859
    {
	 yylhs.value.as< exp_str > ().begin = "label_" + to_string(labelNum);
        labelNum++;
        yylhs.value.as< exp_str > ().after = "label_" + to_string(labelNum);
        labelNum++;
	string tempexp = "label_" + to_string(labelNum);
	labelNum++;
        yylhs.value.as< exp_str > ().code = ": " + yylhs.value.as< exp_str > ().begin + "\n";
        yylhs.value.as< exp_str > ().code += yystack_[5].value.as< exp_str > ().code;
        yylhs.value.as< exp_str > ().code += "! " + yystack_[5].value.as< exp_str > ().place + ", " + yystack_[5].value.as< exp_str > ().place + "\n"; 
        yylhs.value.as< exp_str > ().code += "?:= " + yystack_[1].value.as< exp_str > ().begin + ", " + yystack_[5].value.as< exp_str > ().place + "\n";
        yylhs.value.as< exp_str > ().code += yystack_[3].value.as< exp_str > ().code;
	yylhs.value.as< exp_str > ().code += ":= " + yylhs.value.as< exp_str > ().after + "\n";
	yylhs.value.as< exp_str > ().code += ": " + tempexp + "\n";
	yylhs.value.as< exp_str > ().code += yystack_[1].value.as< exp_str > ().code;
        yylhs.value.as< exp_str > ().code += ": " + yylhs.value.as< exp_str > ().after + "\n";
	}
#line 816 "parser.tab.c" // lalr1.cc:859
    break;

  case 23:
#line 191 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().begin = "label_" + to_string(labelNum);
        labelNum++;
        yylhs.value.as< exp_str > ().after = "label_" + to_string(labelNum);
        labelNum++;
	yylhs.value.as< exp_str > ().code = ": " + yylhs.value.as< exp_str > ().begin + "\n";
	
	yylhs.value.as< exp_str > ().code += yystack_[3].value.as< exp_str > ().code;
        yylhs.value.as< exp_str > ().code += "! " + yystack_[3].value.as< exp_str > ().place + ", " + yystack_[3].value.as< exp_str > ().place + "\n";
        yylhs.value.as< exp_str > ().code += "?:= " + yylhs.value.as< exp_str > ().after + ", " + yystack_[3].value.as< exp_str > ().place + "\n";
	yylhs.value.as< exp_str > ().code += yystack_[1].value.as< exp_str > ().code;
	yylhs.value.as< exp_str > ().code += ":= " + yylhs.value.as< exp_str > ().begin + "\n";
	
	yylhs.value.as< exp_str > ().code += ": " + yylhs.value.as< exp_str > ().after + "\n";
	}
#line 835 "parser.tab.c" // lalr1.cc:859
    break;

  case 24:
#line 206 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().begin = "label_" + to_string(labelNum);
        labelNum++;
        yylhs.value.as< exp_str > ().after = "label_" + to_string(labelNum);
        labelNum++;
	yylhs.value.as< exp_str > ().code = ": " + yylhs.value.as< exp_str > ().begin + "\n";

	yylhs.value.as< exp_str > ().code += yystack_[3].value.as< exp_str > ().code;
	yylhs.value.as< exp_str > ().code += yystack_[0].value.as< exp_str > ().code;
        yylhs.value.as< exp_str > ().code += "?:= " + yylhs.value.as< exp_str > ().begin + ", " + yystack_[0].value.as< exp_str > ().place + "\n";	

	yylhs.value.as< exp_str > ().code += ": " + yylhs.value.as< exp_str > ().after + "\n";
	}
#line 852 "parser.tab.c" // lalr1.cc:859
    break;

  case 25:
#line 219 "part2text.y" // lalr1.cc:859
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
#line 873 "parser.tab.c" // lalr1.cc:859
    break;

  case 26:
#line 236 "part2text.y" // lalr1.cc:859
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
#line 896 "parser.tab.c" // lalr1.cc:859
    break;

  case 27:
#line 255 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = yystack_[0].value.as< exp_str > ().code + "ret " + yystack_[0].value.as< exp_str > ().place + "\n";}
#line 902 "parser.tab.c" // lalr1.cc:859
    break;

  case 28:
#line 258 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().code = yystack_[0].value.as< exp_str > ().code; yylhs.value.as< exp_str > ().place = yystack_[0].value.as< exp_str > ().place;}
#line 909 "parser.tab.c" // lalr1.cc:859
    break;

  case 29:
#line 261 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;
        yylhs.value.as< exp_str > ().code =  yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "|| " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";
	}
#line 919 "parser.tab.c" // lalr1.cc:859
    break;

  case 30:
#line 268 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = yystack_[0].value.as< exp_str > ().code; yylhs.value.as< exp_str > ().place = yystack_[0].value.as< exp_str > ().place;}
#line 925 "parser.tab.c" // lalr1.cc:859
    break;

  case 31:
#line 270 "part2text.y" // lalr1.cc:859
    {            
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;
        yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "&& " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";
	}
#line 935 "parser.tab.c" // lalr1.cc:859
    break;

  case 32:
#line 277 "part2text.y" // lalr1.cc:859
    {                                                          
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;
        yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + yystack_[1].value.as< string > () + " " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";
        }
#line 945 "parser.tab.c" // lalr1.cc:859
    break;

  case 33:
#line 283 "part2text.y" // lalr1.cc:859
    {                                                                                    
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;
        yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + "! " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + "\n" + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + yystack_[1].value.as< string > () +" " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";
	}
#line 955 "parser.tab.c" // lalr1.cc:859
    break;

  case 34:
#line 289 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = ""; yylhs.value.as< exp_str > ().place = "1";}
#line 961 "parser.tab.c" // lalr1.cc:859
    break;

  case 35:
#line 291 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = ""; yylhs.value.as< exp_str > ().place = "0";}
#line 967 "parser.tab.c" // lalr1.cc:859
    break;

  case 36:
#line 293 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = ""; yylhs.value.as< exp_str > ().place = "0";}
#line 973 "parser.tab.c" // lalr1.cc:859
    break;

  case 37:
#line 295 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = ""; yylhs.value.as< exp_str > ().place = "1";}
#line 979 "parser.tab.c" // lalr1.cc:859
    break;

  case 38:
#line 297 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().code = yystack_[1].value.as< exp_str > ().code /*+ "= " + $$.place + ", " + $2.place + "\n"*/;
	yylhs.value.as< exp_str > ().place = yystack_[1].value.as< exp_str > ().place;
	}
#line 988 "parser.tab.c" // lalr1.cc:859
    break;

  case 39:
#line 302 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().code = yystack_[1].value.as< exp_str > ().place + "! " + yystack_[1].value.as< exp_str > ().place + ", " + yystack_[1].value.as< exp_str > ().place + "\n" /*+ "= " + $$.place + ", " + $3.place + "\n"*/;
        yylhs.value.as< exp_str > ().place = yystack_[1].value.as< exp_str > ().place;
	}
#line 997 "parser.tab.c" // lalr1.cc:859
    break;

  case 40:
#line 308 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "==";}
#line 1003 "parser.tab.c" // lalr1.cc:859
    break;

  case 41:
#line 310 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "!=";}
#line 1009 "parser.tab.c" // lalr1.cc:859
    break;

  case 42:
#line 312 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "<";}
#line 1015 "parser.tab.c" // lalr1.cc:859
    break;

  case 43:
#line 314 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = ">";}
#line 1021 "parser.tab.c" // lalr1.cc:859
    break;

  case 44:
#line 316 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "<=";}
#line 1027 "parser.tab.c" // lalr1.cc:859
    break;

  case 45:
#line 318 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = ">=";}
#line 1033 "parser.tab.c" // lalr1.cc:859
    break;

  case 46:
#line 321 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< varz_str > ().base.code = ""; yylhs.value.as< varz_str > ().addOn = list<string>();}
#line 1039 "parser.tab.c" // lalr1.cc:859
    break;

  case 47:
#line 323 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< varz_str > ().base.code = yystack_[0].value.as< exp_str > ().code;yylhs.value.as< varz_str > ().addOn.push_back(yystack_[0].value.as< exp_str > ().place);}
#line 1045 "parser.tab.c" // lalr1.cc:859
    break;

  case 48:
#line 325 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< varz_str > ().base.code = yystack_[1].value.as< exp_str > ().code + yystack_[0].value.as< varz_str > ().base.code;
	yylhs.value.as< varz_str > ().addOn.push_back(yystack_[1].value.as< exp_str > ().place);
	for(list<string>::iterator it = yystack_[0].value.as< varz_str > ().addOn.begin(); it != yystack_[0].value.as< varz_str > ().addOn.end(); it++){
	yylhs.value.as< varz_str > ().addOn.push_back(*it);
	}
	}
#line 1057 "parser.tab.c" // lalr1.cc:859
    break;

  case 49:
#line 334 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< varz_str > ().base.code = yystack_[1].value.as< exp_str > ().code + yystack_[0].value.as< varz_str > ().base.code;
	yylhs.value.as< varz_str > ().addOn.push_back(yystack_[1].value.as< exp_str > ().place);
	for(list<string>::iterator it = yystack_[0].value.as< varz_str > ().addOn.begin(); it != yystack_[0].value.as< varz_str > ().addOn.end(); it++){
	yylhs.value.as< varz_str > ().addOn.push_back(*it);  
	}
	}
#line 1069 "parser.tab.c" // lalr1.cc:859
    break;

  case 50:
#line 342 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< varz_str > ().addOn.push_back(yystack_[0].value.as< exp_str > ().place);
	yylhs.value.as< varz_str > ().base.code = yystack_[0].value.as< exp_str > ().code;
	
	}
#line 1079 "parser.tab.c" // lalr1.cc:859
    break;

  case 51:
#line 349 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = yystack_[0].value.as< exp_str > ().code; yylhs.value.as< exp_str > ().place = yystack_[0].value.as< exp_str > ().place;}
#line 1085 "parser.tab.c" // lalr1.cc:859
    break;

  case 52:
#line 351 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
	tempNum++;
	yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "+ " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";
	 }
#line 1095 "parser.tab.c" // lalr1.cc:859
    break;

  case 53:
#line 357 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;                                                                                                              
	yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "- " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";     
	}
#line 1105 "parser.tab.c" // lalr1.cc:859
    break;

  case 54:
#line 364 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().place = yystack_[0].value.as< exp_str > ().place; yylhs.value.as< exp_str > ().code = yystack_[0].value.as< exp_str > ().code;}
#line 1111 "parser.tab.c" // lalr1.cc:859
    break;

  case 55:
#line 366 "part2text.y" // lalr1.cc:859
    { yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;                                                                                                              
	yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "% " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";
	}
#line 1120 "parser.tab.c" // lalr1.cc:859
    break;

  case 56:
#line 371 "part2text.y" // lalr1.cc:859
    { yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;                                                                                                              
	yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "/ " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";}
#line 1128 "parser.tab.c" // lalr1.cc:859
    break;

  case 57:
#line 375 "part2text.y" // lalr1.cc:859
    { yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
        tempNum++;
	yylhs.value.as< exp_str > ().code = yystack_[2].value.as< exp_str > ().code + yystack_[0].value.as< exp_str > ().code + ". " + yylhs.value.as< exp_str > ().place + "\n" + "* " + yylhs.value.as< exp_str > ().place + ", " + yystack_[2].value.as< exp_str > ().place + ", " + yystack_[0].value.as< exp_str > ().place + "\n";}
#line 1136 "parser.tab.c" // lalr1.cc:859
    break;

  case 58:
#line 380 "part2text.y" // lalr1.cc:859
    { 
	yylhs.value.as< exp_str > ().place = yystack_[0].value.as< varz_str > ().base.place; yylhs.value.as< exp_str > ().code = yystack_[0].value.as< varz_str > ().base.code;
        }
#line 1144 "parser.tab.c" // lalr1.cc:859
    break;

  case 59:
#line 384 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().place = yystack_[0].value.as< varz_str > ().base.place; yylhs.value.as< exp_str > ().code = yystack_[0].value.as< varz_str > ().base.code + "- " + yystack_[0].value.as< varz_str > ().base.place + ", 0, " + yystack_[0].value.as< varz_str > ().base.place + "\n";}
#line 1150 "parser.tab.c" // lalr1.cc:859
    break;

  case 60:
#line 386 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().place = to_string(yystack_[0].value.as< int > ()); yylhs.value.as< exp_str > ().code = "";}
#line 1156 "parser.tab.c" // lalr1.cc:859
    break;

  case 61:
#line 388 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().place = "-" + to_string(yystack_[0].value.as< int > ()); yylhs.value.as< exp_str > ().code = "";}
#line 1162 "parser.tab.c" // lalr1.cc:859
    break;

  case 62:
#line 390 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< exp_str > ().code = yystack_[1].value.as< exp_str > ().code + "= " + yylhs.value.as< exp_str > ().place + ", " + yystack_[1].value.as< exp_str > ().place + "\n"; yylhs.value.as< exp_str > ().place = yystack_[1].value.as< exp_str > ().place;}
#line 1168 "parser.tab.c" // lalr1.cc:859
    break;

  case 63:
#line 392 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().code = yystack_[1].value.as< exp_str > ().code;
	yylhs.value.as< exp_str > ().code += "= " + yylhs.value.as< exp_str > ().place + ", " + yystack_[1].value.as< exp_str > ().place + "\n"; 
	yylhs.value.as< exp_str > ().code += "- " + yylhs.value.as< exp_str > ().place + ", 0, " + yylhs.value.as< exp_str > ().place + "\n";
	yylhs.value.as< exp_str > ().place = yystack_[1].value.as< exp_str > ().place;
	}
#line 1179 "parser.tab.c" // lalr1.cc:859
    break;

  case 64:
#line 399 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< exp_str > ().place = "temp_" + to_string(tempNum);
	tempNum++;
	yylhs.value.as< exp_str > ().code = yystack_[1].value.as< varz_str > ().base.code;
	for(list<string>::iterator it = yystack_[1].value.as< varz_str > ().addOn.begin(); it != yystack_[1].value.as< varz_str > ().addOn.end();it++){
	yylhs.value.as< exp_str > ().code += "param " + *it + "\n";
	}  
	yylhs.value.as< exp_str > ().code	+= ". " + yylhs.value.as< exp_str > ().place + "\n" + "call " + yystack_[3].value.as< string > () + ", " + yylhs.value.as< exp_str > ().place + "\n";
	}
#line 1193 "parser.tab.c" // lalr1.cc:859
    break;

  case 65:
#line 410 "part2text.y" // lalr1.cc:859
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
#line 1209 "parser.tab.c" // lalr1.cc:859
    break;

  case 66:
#line 422 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< varz_str > ().addOn = yystack_[0].value.as< varz_str > ().addOn; yylhs.value.as< varz_str > ().id = yystack_[0].value.as< varz_str > ().id;}
#line 1215 "parser.tab.c" // lalr1.cc:859
    break;

  case 67:
#line 425 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< varz_str > ().base.place = yystack_[0].value.as< string > ();yylhs.value.as< varz_str > ().addOn.push_back(yystack_[0].value.as< string > ());yylhs.value.as< varz_str > ().id.push_back("__");}
#line 1221 "parser.tab.c" // lalr1.cc:859
    break;

  case 68:
#line 427 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< varz_str > ().base.place = "temp_" + to_string(tempNum);
	tempNum++;
	yylhs.value.as< varz_str > ().base.code = ". " + yylhs.value.as< varz_str > ().base.place + "\n" + "=[] " + yylhs.value.as< varz_str > ().base.place + ", " + yystack_[3].value.as< string > () + ", " + yystack_[1].value.as< exp_str > ().place + "\n";
	yylhs.value.as< varz_str > ().addOn.push_back(yystack_[3].value.as< string > ());
	yylhs.value.as< varz_str > ().id.push_back(yystack_[1].value.as< exp_str > ().place);
	}
#line 1233 "parser.tab.c" // lalr1.cc:859
    break;


#line 1237 "parser.tab.c" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -62;

  const signed char parser::yytable_ninf_ = -18;

  const short int
  parser::yypact_[] =
  {
      32,    15,    37,   -62,    32,   -62,    36,   -62,   -62,    47,
       8,    44,    35,    49,     1,    45,   -62,    54,    94,     7,
       7,    10,   -62,    18,   -62,   -62,   -62,    66,   109,    75,
     110,    70,    81,   108,    78,    85,    85,   104,    83,    83,
     -15,    77,   119,     2,    79,   120,   -62,    30,   -62,   -62,
     -13,   -14,   -62,    85,   131,   121,   123,   103,    11,    29,
     -62,   129,    81,   -62,   105,   -62,   -15,   -62,   -15,   -62,
     -62,   -62,    68,   -15,   -62,   -62,   -62,    85,   103,   -62,
     -15,   -62,   -15,   102,    97,    81,    85,    85,   -62,   -62,
     -62,   -62,   -62,   -62,   -15,   -15,   -15,   -15,   -15,   -15,
      81,   132,    83,   106,   107,   -62,   -62,   111,   -15,   112,
     113,   116,   -62,   -62,    59,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   134,   138,   -62,   -62,   -62,   -62,   -62,
     -62,   -15,   -62,   -62,    81,   -62,    85,   116,   136,   -62,
     -62,   -62
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,     0,     2,     3,     6,     0,     1,     4,     0,
       0,     0,    15,     0,     0,     0,    10,     0,     0,     0,
       0,     0,    14,     0,    11,     9,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,     0,     0,     0,    18,     0,    34,    36,
       0,    67,    60,     0,     0,    28,    30,     0,    51,    54,
      58,     0,     0,    25,    66,    26,     0,    27,     0,     7,
       5,    19,     0,     0,    12,    35,    37,     0,     0,    61,
       0,    59,    46,     0,     0,     0,     0,     0,    40,    41,
      42,    43,    44,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    20,     0,     0,     0,
       0,    47,    38,    62,     0,    29,    31,    32,    53,    52,
      57,    56,    55,     0,     0,    65,    68,    39,    33,    63,
      64,     0,    48,    21,     0,    23,     0,    50,     0,    24,
      49,    22
  };

  const short int
  parser::yypgoto_[] =
  {
     -62,   -62,   153,   -62,   -62,    73,   -62,   145,   -61,   -62,
     -31,    76,   -62,    86,   -62,    28,   -30,     9,   -62,   -35,
     -32
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    70,    13,    14,    15,    42,    43,
      54,    55,    56,    94,   110,   132,    57,    58,    59,    63,
      60
  };

  const short int
  parser::yytable_[] =
  {
      44,   101,    19,    71,    65,    61,    64,    64,    11,    11,
      67,   105,    -8,    -8,    -8,    50,     5,    78,    81,    11,
      26,    27,    83,    84,   114,    -8,    51,    52,    41,    79,
      44,    66,    82,    80,    68,     1,   103,     7,   104,   123,
      44,    95,    96,   106,    20,    72,   107,    84,    12,    12,
     109,    10,   111,    44,    18,   115,     6,    75,    76,    12,
      50,    97,    98,    99,   117,   118,   119,   125,    44,    34,
      64,    51,    52,   138,   133,   134,    77,   -17,   128,     9,
      17,    35,    34,   -17,   -17,    36,    37,    16,   -17,    21,
      38,    39,    24,    25,    35,    12,    28,    40,    36,    37,
      23,   137,    44,    38,    39,   139,   120,   121,   122,    41,
      40,    47,    48,    49,    29,    50,    30,    31,    32,    33,
      45,    46,    41,    62,    41,    68,    51,    52,    69,    73,
      74,    53,    88,    89,    90,    91,    92,    93,    88,    89,
      90,    91,    92,    93,   113,    85,    86,    87,   100,   112,
     102,   141,   124,   113,   135,   136,   126,     8,   127,   129,
     130,   131,    22,   116,   108,   140
  };

  const unsigned char
  parser::yycheck_[] =
  {
      32,    62,     1,     1,    39,    36,    38,    39,     1,     1,
      40,    72,     5,     5,     7,    30,     1,    47,    50,     1,
      10,    11,    53,    53,    85,     7,    41,    42,    41,    42,
      62,    46,    46,    46,    48,     3,    66,     0,    68,   100,
      72,    30,    31,    73,    43,    43,    77,    77,    41,    41,
      80,     4,    82,    85,     5,    86,    41,    27,    28,    41,
      30,    32,    33,    34,    94,    95,    96,   102,   100,     1,
     102,    41,    42,   134,    15,    16,    46,     9,   108,    43,
      45,    13,     1,    15,    16,    17,    18,    43,    20,    44,
      22,    23,    19,    20,    13,    41,    23,    29,    17,    18,
       6,   131,   134,    22,    23,   136,    97,    98,    99,    41,
      29,    26,    27,    28,    48,    30,     7,    42,     8,    49,
      12,    43,    41,    19,    41,    48,    41,    42,     9,    50,
      10,    46,    35,    36,    37,    38,    39,    40,    35,    36,
      37,    38,    39,    40,    47,    14,    25,    24,    19,    47,
      45,    15,    20,    47,    20,    17,    49,     4,    47,    47,
      47,    45,    17,    87,    78,   137
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    53,    54,    55,     1,    41,     0,    54,    43,
       4,     1,    41,    57,    58,    59,    43,    45,     5,     1,
      43,    44,    59,     6,    57,    57,    10,    11,    57,    48,
       7,    42,     8,    49,     1,    13,    17,    18,    22,    23,
      29,    41,    60,    61,    72,    12,    43,    26,    27,    28,
      30,    41,    42,    46,    62,    63,    64,    68,    69,    70,
      72,    62,    19,    71,    72,    71,    46,    68,    48,     9,
      56,     1,    43,    50,    10,    27,    28,    46,    68,    42,
      46,    72,    46,    62,    68,    14,    25,    24,    35,    36,
      37,    38,    39,    40,    65,    30,    31,    32,    33,    34,
      19,    60,    45,    68,    68,    60,    68,    62,    65,    68,
      66,    68,    47,    47,    60,    62,    63,    68,    68,    68,
      69,    69,    69,    60,    20,    71,    49,    47,    68,    47,
      47,    45,    67,    15,    16,    20,    17,    68,    60,    62,
      67,    15
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    52,    53,    54,    54,    55,    55,    56,    57,    57,
      57,    57,    58,    58,    59,    59,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    65,    65,    66,    66,    66,    67,
      67,    68,    68,    68,    69,    69,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    72
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,    12,     2,     1,     0,     3,
       2,     3,     8,     3,     3,     1,     3,     2,     2,     2,
       3,     5,     7,     5,     6,     2,     2,     2,     1,     3,
       1,     3,     3,     4,     1,     2,     1,     2,     3,     4,
       1,     1,     1,     1,     1,     1,     0,     1,     2,     3,
       2,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       1,     2,     3,     4,     4,     3,     1,     1,     4
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
  "endTrigger", "declarationsWsemi", "declaration", "idents",
  "statementzWsemi", "statement", "boolExpression",
  "relationAndExpression", "relationExpression", "comp",
  "expressionzWcomma", "expressionCommaChain", "expression",
  "multiplicativeExpression", "term", "varzWcomma", "var", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,    84,    84,    88,    89,    92,   103,   106,   113,   114,
     122,   124,   126,   128,   134,   140,   147,   150,   152,   154,
     157,   159,   172,   190,   205,   218,   235,   254,   257,   260,
     267,   269,   276,   282,   288,   290,   292,   294,   296,   301,
     307,   309,   311,   313,   315,   317,   321,   322,   324,   333,
     341,   348,   350,   356,   363,   365,   370,   374,   379,   383,
     385,   387,   389,   391,   398,   409,   421,   424,   426
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
#line 1707 "parser.tab.c" // lalr1.cc:1167
#line 437 "part2text.y" // lalr1.cc:1168


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



