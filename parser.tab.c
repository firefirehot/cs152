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
#line 24 "part2text.y" // lalr1.cc:413


#include "parser.tab.h"

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

#line 77 "parser.tab.c" // lalr1.cc:413


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
#line 163 "parser.tab.c" // lalr1.cc:479

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
      case 42: // NUMBER
        value.move< int > (that.value);
        break;

      case 41: // IDENT
      case 54: // program
      case 55: // function
      case 56: // declarationsWsemi
      case 57: // declaration
      case 58: // idents
      case 59: // statementzWsemi
      case 60: // statement
        value.move< string > (that.value);
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
      case 42: // NUMBER
        value.copy< int > (that.value);
        break;

      case 41: // IDENT
      case 54: // program
      case 55: // function
      case 56: // declarationsWsemi
      case 57: // declaration
      case 58: // idents
      case 59: // statementzWsemi
      case 60: // statement
        value.copy< string > (that.value);
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
      case 42: // NUMBER
        yylhs.value.build< int > ();
        break;

      case 41: // IDENT
      case 54: // program
      case 55: // function
      case 56: // declarationsWsemi
      case 57: // declaration
      case 58: // idents
      case 59: // statementzWsemi
      case 60: // statement
        yylhs.value.build< string > ();
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
#line 67 "part2text.y" // lalr1.cc:859
    {if(no_error) cout << yystack_[0].value.as< string > () << endl;}
#line 581 "parser.tab.c" // lalr1.cc:859
    break;

  case 3:
#line 71 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "";}
#line 587 "parser.tab.c" // lalr1.cc:859
    break;

  case 4:
#line 73 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = yystack_[1].value.as< string > () + "\n" + yystack_[0].value.as< string > ();}
#line 593 "parser.tab.c" // lalr1.cc:859
    break;

  case 5:
#line 76 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "func " + yystack_[10].value.as< string > () + "\n";
	yylhs.value.as< string > () += yystack_[7].value.as< string > ();
	yylhs.value.as< string > () += yystack_[4].value.as< string > ();
	yylhs.value.as< string > () += yystack_[1].value.as< string > ();
	yylhs.value.as< string > () += "endfunc \n";
	}
#line 604 "parser.tab.c" // lalr1.cc:859
    break;

  case 6:
#line 83 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "";}
#line 610 "parser.tab.c" // lalr1.cc:859
    break;

  case 7:
#line 86 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "";}
#line 616 "parser.tab.c" // lalr1.cc:859
    break;

  case 8:
#line 88 "part2text.y" // lalr1.cc:859
    {
	yylhs.value.as< string > () = yystack_[2].value.as< string > () + yystack_[0].value.as< string > ();
	}
#line 624 "parser.tab.c" // lalr1.cc:859
    break;

  case 9:
#line 92 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "";}
#line 630 "parser.tab.c" // lalr1.cc:859
    break;

  case 11:
#line 96 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "declaration \n";}
#line 636 "parser.tab.c" // lalr1.cc:859
    break;

  case 12:
#line 98 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = ". " + yystack_[2].value.as< string > () + "\n";}
#line 642 "parser.tab.c" // lalr1.cc:859
    break;

  case 13:
#line 101 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = yystack_[2].value.as< string > () + yystack_[0].value.as< string > ();}
#line 648 "parser.tab.c" // lalr1.cc:859
    break;

  case 14:
#line 103 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = yystack_[0].value.as< string > ();}
#line 654 "parser.tab.c" // lalr1.cc:859
    break;

  case 15:
#line 106 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = yystack_[2].value.as< string > () + yystack_[0].value.as< string > (); }
#line 660 "parser.tab.c" // lalr1.cc:859
    break;

  case 16:
#line 108 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = yystack_[1].value.as< string > ();}
#line 666 "parser.tab.c" // lalr1.cc:859
    break;

  case 17:
#line 110 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "";}
#line 672 "parser.tab.c" // lalr1.cc:859
    break;

  case 18:
#line 112 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "";}
#line 678 "parser.tab.c" // lalr1.cc:859
    break;

  case 19:
#line 115 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "statement \n";}
#line 684 "parser.tab.c" // lalr1.cc:859
    break;

  case 20:
#line 117 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "statement \n";}
#line 690 "parser.tab.c" // lalr1.cc:859
    break;

  case 21:
#line 119 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "statement \n";}
#line 696 "parser.tab.c" // lalr1.cc:859
    break;

  case 22:
#line 121 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "statement \n";}
#line 702 "parser.tab.c" // lalr1.cc:859
    break;

  case 23:
#line 123 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "statement \n";}
#line 708 "parser.tab.c" // lalr1.cc:859
    break;

  case 24:
#line 125 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "statement \n";}
#line 714 "parser.tab.c" // lalr1.cc:859
    break;

  case 25:
#line 127 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "statement \n";}
#line 720 "parser.tab.c" // lalr1.cc:859
    break;

  case 26:
#line 129 "part2text.y" // lalr1.cc:859
    {yylhs.value.as< string > () = "statement \n";}
#line 726 "parser.tab.c" // lalr1.cc:859
    break;


#line 730 "parser.tab.c" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -64;

  const signed char parser::yytable_ninf_ = -17;

  const short int
  parser::yypact_[] =
  {
      21,    12,    37,   -64,    21,   -64,    -2,   -64,   -64,    43,
      15,    45,     5,    81,     0,    48,   -64,    50,    88,    14,
      14,    47,   -64,     7,   -64,   -64,   -64,    51,    98,    53,
      99,    57,    80,   101,    72,    84,    84,    97,    78,    78,
      29,    74,   114,     1,    77,   118,   -64,    90,   -64,   -64,
     -15,   -37,   -64,    84,   110,   104,   109,   108,    42,    28,
     -64,   115,    80,   -64,   105,   -64,    29,   -64,    29,   -64,
     -64,    67,    29,   -64,   -64,   -64,    84,   108,   -64,    29,
     -64,    29,   106,   102,    80,    84,    84,   -64,   -64,   -64,
     -64,   -64,   -64,    29,    29,    29,    29,    29,    29,    80,
     131,    78,   107,    86,   -64,   -64,   111,    29,   112,   113,
     116,   -64,   -64,    63,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   132,   138,   -64,   -64,   -64,   -64,   -64,   -64,
      29,   -64,   -64,    80,   -64,    84,   116,   141,   -64,   -64,
     -64
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,     0,     2,     3,     6,     0,     1,     4,     0,
       0,     0,    14,     0,     0,     0,     9,     0,     0,     0,
       0,     0,    13,     0,    10,     8,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,     0,     0,     0,     0,    17,     0,    33,    35,
       0,    66,    59,     0,     0,    27,    29,     0,    50,    53,
      57,     0,     0,    24,    65,    25,     0,    26,     0,     5,
      18,     0,     0,    11,    34,    36,     0,     0,    60,     0,
      58,    45,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,    19,     0,     0,     0,     0,
      46,    37,    61,     0,    28,    30,    31,    52,    51,    56,
      55,    54,     0,     0,    64,    67,    38,    32,    62,    63,
       0,    47,    20,     0,    22,     0,    49,     0,    23,    48,
      21
  };

  const short int
  parser::yypgoto_[] =
  {
     -64,   -64,   153,   -64,     9,   -64,   145,   -59,   -64,   -31,
      79,   -64,    87,   -64,    27,   -30,   -63,   -64,   -35,   -32
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    13,    14,    15,    42,    43,    54,
      55,    56,    93,   109,   131,    57,    58,    59,    63,    60
  };

  const short int
  parser::yytable_[] =
  {
      44,    19,    70,   100,    65,    61,    64,    64,    11,    81,
      67,    68,   104,     5,    -7,    11,    11,    77,    80,    -7,
      -7,    -7,    82,    83,     1,   113,    41,    78,    24,    25,
      44,    79,    28,   119,   120,   121,   102,     7,   103,    44,
     122,     9,   105,    20,    71,   106,    83,    10,    12,   108,
      17,   110,    44,     6,   114,    12,    12,    26,    27,    50,
      96,    97,    98,   116,   117,   118,   124,    44,    34,    64,
      51,    52,    94,    95,   137,    66,   -16,   127,   132,   133,
      35,    34,   -16,   -16,    36,    37,    18,   -16,    16,    38,
      39,    12,    21,    35,    23,    31,    40,    36,    37,    29,
     136,    44,    38,    39,   138,    30,    33,    32,    41,    40,
      47,    48,    49,    45,    50,    46,    62,    74,    75,    41,
      50,    41,    68,    69,    84,    51,    52,    72,    73,    85,
      53,    51,    52,    86,    99,   125,    76,    87,    88,    89,
      90,    91,    92,    87,    88,    89,    90,    91,    92,   112,
     101,   123,   134,   111,   112,   135,   140,     8,   126,   128,
     129,   130,    22,   139,   107,   115
  };

  const unsigned char
  parser::yycheck_[] =
  {
      32,     1,     1,    62,    39,    36,    38,    39,     1,    46,
      40,    48,    71,     1,     7,     1,     1,    47,    50,     5,
       5,     7,    53,    53,     3,    84,    41,    42,    19,    20,
      62,    46,    23,    96,    97,    98,    66,     0,    68,    71,
      99,    43,    72,    43,    43,    76,    76,     4,    41,    79,
      45,    81,    84,    41,    85,    41,    41,    10,    11,    30,
      32,    33,    34,    93,    94,    95,   101,    99,     1,   101,
      41,    42,    30,    31,   133,    46,     9,   107,    15,    16,
      13,     1,    15,    16,    17,    18,     5,    20,    43,    22,
      23,    41,    44,    13,     6,    42,    29,    17,    18,    48,
     130,   133,    22,    23,   135,     7,    49,     8,    41,    29,
      26,    27,    28,    12,    30,    43,    19,    27,    28,    41,
      30,    41,    48,     9,    14,    41,    42,    50,    10,    25,
      46,    41,    42,    24,    19,    49,    46,    35,    36,    37,
      38,    39,    40,    35,    36,    37,    38,    39,    40,    47,
      45,    20,    20,    47,    47,    17,    15,     4,    47,    47,
      47,    45,    17,   136,    77,    86
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    53,    54,    55,     1,    41,     0,    54,    43,
       4,     1,    41,    56,    57,    58,    43,    45,     5,     1,
      43,    44,    58,     6,    56,    56,    10,    11,    56,    48,
       7,    42,     8,    49,     1,    13,    17,    18,    22,    23,
      29,    41,    59,    60,    71,    12,    43,    26,    27,    28,
      30,    41,    42,    46,    61,    62,    63,    67,    68,    69,
      71,    61,    19,    70,    71,    70,    46,    67,    48,     9,
       1,    43,    50,    10,    27,    28,    46,    67,    42,    46,
      71,    46,    61,    67,    14,    25,    24,    35,    36,    37,
      38,    39,    40,    64,    30,    31,    32,    33,    34,    19,
      59,    45,    67,    67,    59,    67,    61,    64,    67,    65,
      67,    47,    47,    59,    61,    62,    67,    67,    67,    68,
      68,    68,    59,    20,    70,    49,    47,    67,    47,    47,
      45,    66,    15,    16,    20,    17,    67,    59,    61,    66,
      15
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    52,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    65,    65,    65,    66,    66,
      67,    67,    67,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    71,    71
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,    12,     2,     0,     3,     2,
       3,     8,     3,     3,     1,     3,     2,     2,     2,     3,
       5,     7,     5,     6,     2,     2,     2,     1,     3,     1,
       3,     3,     4,     1,     2,     1,     2,     3,     4,     1,
       1,     1,     1,     1,     1,     0,     1,     2,     3,     2,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     1,
       2,     3,     4,     4,     3,     1,     1,     4
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
  "relationExpression", "comp", "expressionzWcomma",
  "expressionCommaChain", "expression", "multiplicativeExpression", "term",
  "varzWcomma", "var", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    67,    67,    71,    72,    75,    82,    86,    87,    91,
      93,    95,    97,   100,   102,   105,   107,   109,   111,   114,
     116,   118,   120,   122,   124,   126,   128,   131,   133,   136,
     138,   141,   143,   145,   147,   149,   151,   153,   155,   158,
     160,   162,   164,   166,   168,   171,   172,   173,   175,   176,
     178,   180,   182,   185,   187,   189,   191,   194,   196,   198,
     200,   202,   204,   206,   209,   210,   212,   214
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
#line 1198 "parser.tab.c" // lalr1.cc:1167
#line 219 "part2text.y" // lalr1.cc:1168


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
	//std::cout << l << ": " << m << std::endl;
	  no_error = false;
   if(errorArrayCount < 30){
        errorArray[errorArrayCount] = 
		"Error in column " + to_string(col_c) + " row" + to_string(row_c) + " : " + m + "\n";
        errorArrayCount++;
}
}



