/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser3.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include the Bison-generated header file
#include "parser3.tab.h"

extern FILE *yyin;
extern int yylineno;
extern char *yytext;
extern int yylex();
void yyerror(const char *s);

// Error counter and structure to store errors
int error_count = 0;

typedef struct Error {
    int line;
    char *message;
    struct Error *next;
} Error;

Error *error_list = NULL;

void add_error(int line, const char *message) {
    Error *new_error = (Error *)malloc(sizeof(Error));
    new_error->line = line;
    new_error->message = strdup(message);
    new_error->next = error_list;
    error_list = new_error;
    
    // Debugging message
    fprintf(stderr, "Stored error: %s at line %d\n", message, line);
}

void print_errors() {
    Error *current = error_list;
    while (current != NULL) {
        fprintf(stderr, "Printing error: %s at line %d\n", current->message, current->line); // Debugging message
        fprintf(stderr, "Error: %s at line %d\n", current->message, current->line);
        Error *next = current->next;
        free(current->message);
        free(current);
        current = next;
    }
    error_list = NULL;
}


#line 122 "parser3.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser3.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CAPITALIZED_IDENTIFIER = 4,     /* CAPITALIZED_IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 6,               /* CHAR_LITERAL  */
  YYSYMBOL_NUMBER = 7,                     /* NUMBER  */
  YYSYMBOL_PUBLIC = 8,                     /* PUBLIC  */
  YYSYMBOL_PRIVATE = 9,                    /* PRIVATE  */
  YYSYMBOL_CLASS = 10,                     /* CLASS  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_CHAR = 12,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 13,                    /* DOUBLE  */
  YYSYMBOL_BOOLEAN = 14,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 15,                    /* STRING  */
  YYSYMBOL_VOID = 16,                      /* VOID  */
  YYSYMBOL_NEW = 17,                       /* NEW  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_SWITCH = 24,                    /* SWITCH  */
  YYSYMBOL_CASE = 25,                      /* CASE  */
  YYSYMBOL_DEFAULT = 26,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 27,                     /* BREAK  */
  YYSYMBOL_BOOLEAN_LITERAL = 28,           /* BOOLEAN_LITERAL  */
  YYSYMBOL_OUT_PRINT = 29,                 /* OUT_PRINT  */
  YYSYMBOL_THEN = 30,                      /* THEN  */
  YYSYMBOL_LPAREN = 31,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 32,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 33,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 34,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 35,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 36,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 37,                    /* ASSIGN  */
  YYSYMBOL_EQ = 38,                        /* EQ  */
  YYSYMBOL_NEQ = 39,                       /* NEQ  */
  YYSYMBOL_LT = 40,                        /* LT  */
  YYSYMBOL_GT = 41,                        /* GT  */
  YYSYMBOL_LE = 42,                        /* LE  */
  YYSYMBOL_GE = 43,                        /* GE  */
  YYSYMBOL_AND = 44,                       /* AND  */
  YYSYMBOL_OR = 45,                        /* OR  */
  YYSYMBOL_PLUS = 46,                      /* PLUS  */
  YYSYMBOL_MINUS = 47,                     /* MINUS  */
  YYSYMBOL_MUL = 48,                       /* MUL  */
  YYSYMBOL_DIV = 49,                       /* DIV  */
  YYSYMBOL_DOT = 50,                       /* DOT  */
  YYSYMBOL_COLON = 51,                     /* COLON  */
  YYSYMBOL_LOWER_THAN_ELSE = 52,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_53_ = 53,                       /* "!"  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_class_declaration_list = 56,    /* class_declaration_list  */
  YYSYMBOL_class_declaration = 57,         /* class_declaration  */
  YYSYMBOL_class_body = 58,                /* class_body  */
  YYSYMBOL_variable_declaration_list = 59, /* variable_declaration_list  */
  YYSYMBOL_variable_declaration = 60,      /* variable_declaration  */
  YYSYMBOL_variable_declarators = 61,      /* variable_declarators  */
  YYSYMBOL_variable_declarator = 62,       /* variable_declarator  */
  YYSYMBOL_modifier = 63,                  /* modifier  */
  YYSYMBOL_method_declaration_list = 64,   /* method_declaration_list  */
  YYSYMBOL_method_declaration = 65,        /* method_declaration  */
  YYSYMBOL_parameter_list = 66,            /* parameter_list  */
  YYSYMBOL_parameter = 67,                 /* parameter  */
  YYSYMBOL_method_body = 68,               /* method_body  */
  YYSYMBOL_statement_list = 69,            /* statement_list  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_assignment_statement = 71,      /* assignment_statement  */
  YYSYMBOL_loop_statement = 72,            /* loop_statement  */
  YYSYMBOL_for_init = 73,                  /* for_init  */
  YYSYMBOL_for_increment = 74,             /* for_increment  */
  YYSYMBOL_control_statement = 75,         /* control_statement  */
  YYSYMBOL_switch_statement = 76,          /* switch_statement  */
  YYSYMBOL_case_clauses = 77,              /* case_clauses  */
  YYSYMBOL_case_clause = 78,               /* case_clause  */
  YYSYMBOL_default_clause_opt = 79,        /* default_clause_opt  */
  YYSYMBOL_print_statement = 80,           /* print_statement  */
  YYSYMBOL_print_argument_list = 81,       /* print_argument_list  */
  YYSYMBOL_return_statement = 82,          /* return_statement  */
  YYSYMBOL_break_statement = 83,           /* break_statement  */
  YYSYMBOL_block_statement = 84,           /* block_statement  */
  YYSYMBOL_expression_opt = 85,            /* expression_opt  */
  YYSYMBOL_condition_opt = 86,             /* condition_opt  */
  YYSYMBOL_condition = 87,                 /* condition  */
  YYSYMBOL_relational_operator = 88,       /* relational_operator  */
  YYSYMBOL_expression = 89,                /* expression  */
  YYSYMBOL_binary_expression = 90,         /* binary_expression  */
  YYSYMBOL_unary_expression = 91,          /* unary_expression  */
  YYSYMBOL_method_call = 92,               /* method_call  */
  YYSYMBOL_object_creation = 93,           /* object_creation  */
  YYSYMBOL_argument_list = 94,             /* argument_list  */
  YYSYMBOL_literal = 95,                   /* literal  */
  YYSYMBOL_binary_operator = 96,           /* binary_operator  */
  YYSYMBOL_unary_operator = 97,            /* unary_operator  */
  YYSYMBOL_type = 98                       /* type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   423

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   124,   124,   128,   129,   133,   134,   138,   142,   143,
     144,   148,   149,   153,   154,   158,   159,   163,   164,   168,
     169,   170,   174,   175,   179,   180,   181,   185,   189,   190,
     194,   195,   196,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   212,   216,   217,   221,   222,   223,   224,   228,
     229,   233,   234,   238,   242,   243,   247,   251,   252,   256,
     260,   261,   262,   266,   270,   274,   275,   279,   280,   284,
     285,   289,   290,   294,   295,   296,   297,   298,   299,   303,
     304,   305,   306,   307,   308,   312,   316,   320,   324,   328,
     329,   330,   334,   335,   336,   337,   341,   342,   343,   344,
     345,   346,   350,   351,   355,   356,   357,   358,   359,   360,
     361
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CAPITALIZED_IDENTIFIER", "STRING_LITERAL", "CHAR_LITERAL", "NUMBER",
  "PUBLIC", "PRIVATE", "CLASS", "INT", "CHAR", "DOUBLE", "BOOLEAN",
  "STRING", "VOID", "NEW", "RETURN", "IF", "ELSE", "WHILE", "DO", "FOR",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "BOOLEAN_LITERAL", "OUT_PRINT",
  "THEN", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", "COMMA",
  "ASSIGN", "EQ", "NEQ", "LT", "GT", "LE", "GE", "AND", "OR", "PLUS",
  "MINUS", "MUL", "DIV", "DOT", "COLON", "LOWER_THAN_ELSE", "\"!\"",
  "$accept", "program", "class_declaration_list", "class_declaration",
  "class_body", "variable_declaration_list", "variable_declaration",
  "variable_declarators", "variable_declarator", "modifier",
  "method_declaration_list", "method_declaration", "parameter_list",
  "parameter", "method_body", "statement_list", "statement",
  "assignment_statement", "loop_statement", "for_init", "for_increment",
  "control_statement", "switch_statement", "case_clauses", "case_clause",
  "default_clause_opt", "print_statement", "print_argument_list",
  "return_statement", "break_statement", "block_statement",
  "expression_opt", "condition_opt", "condition", "relational_operator",
  "expression", "binary_expression", "unary_expression", "method_call",
  "object_creation", "argument_list", "literal", "binary_operator",
  "unary_operator", "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-111)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,     6,     5,    41,    16,  -161,    44,    29,  -161,  -161,
      48,   373,   373,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,    49,   373,  -161,   387,   104,    77,  -161,  -161,
     387,   373,  -161,   112,   104,    79,    -1,  -161,  -161,   114,
     387,  -161,   115,   -18,    15,   107,  -161,   104,    -6,   118,
      91,   387,  -161,    76,  -161,  -161,  -161,   128,  -161,  -161,
    -161,   347,  -161,  -161,  -161,  -161,  -161,   107,  -161,   387,
     103,     0,  -161,   146,   152,   126,  -161,  -161,  -161,  -161,
    -161,  -161,   107,   347,    40,   130,   387,  -161,   133,   127,
     347,   132,   129,  -161,   107,  -161,   129,    36,   124,   107,
     136,   137,   140,   141,   147,   154,   165,  -161,   156,   350,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,   347,
      46,   157,  -161,  -161,   107,   151,   347,   107,   192,    52,
     107,  -161,   191,    63,   215,  -161,  -161,  -161,   107,  -161,
      42,  -161,   167,   366,   162,   242,     2,  -161,  -161,   174,
     347,    -2,   166,  -161,  -161,   347,  -161,   179,  -161,  -161,
    -161,  -161,  -161,  -161,   107,   196,   107,   180,   107,    60,
     192,   347,   189,   187,  -161,  -161,   347,   197,   107,   269,
     107,   122,    69,  -161,   347,   216,   203,   -29,  -161,   208,
     347,   107,   190,  -161,   209,   213,   212,   219,   372,   192,
    -161,   192,  -161,   192,   192,   350,   296,   323,   350,  -161,
    -161
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     0,     0,     1,     4,
       0,    10,    10,   110,    17,    18,   104,   105,   106,   107,
     108,   109,     0,    21,     8,     0,     0,     0,     6,     9,
       0,     7,    19,     0,     0,    15,     0,    14,     5,     0,
       0,    20,     0,    15,     0,     0,    11,     0,    15,     0,
       0,    26,    12,    80,    94,    93,    92,     0,    95,   102,
     103,    16,    81,    82,    83,    84,    79,     0,    13,    26,
       0,     0,    24,     0,     0,     0,   100,   101,    96,    97,
      98,    99,     0,    86,     0,     0,     0,    27,     0,     0,
      85,     0,     0,    25,    89,    88,     0,     0,   110,    67,
       0,     0,     0,     0,     0,     0,     0,    41,     0,    28,
      30,    33,    34,    35,    40,    36,    37,    38,    39,    90,
       0,     0,    29,    32,     0,     0,    68,     0,     0,    48,
       0,    64,     0,     0,     0,    23,    31,    87,     0,    22,
       0,    63,     0,    72,     0,     0,    80,    45,    46,     0,
      47,     0,    60,    66,    65,    91,    42,     0,    75,    76,
      73,    74,    77,    78,     0,     0,    69,     0,     0,     0,
       0,    71,     0,     0,    70,    54,    61,     0,     0,     0,
       0,     0,    57,    59,    62,    51,     0,    80,    49,     0,
      50,     0,     0,    55,     0,     0,     0,     0,     0,     0,
      53,     0,    43,     0,     0,    58,     0,     0,    56,    52,
      44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,  -161,   255,   250,  -161,    -9,   -11,   220,   -16,
    -161,   232,   199,   184,   177,   -95,  -105,  -128,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -160,  -161,   -45,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,   -13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,    22,    23,   107,    36,    37,    25,
      31,    32,    71,    72,   108,   109,   110,   111,   112,   149,
     189,   113,   114,   182,   193,   194,   115,   169,   116,   117,
     118,   125,   173,   142,   164,   143,    62,    63,    64,    65,
     120,    66,    82,    67,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,   148,    24,    24,   136,  -110,   174,    30,   124,     7,
      33,   134,    34,    51,    29,    40,     6,    39,    42,    45,
     186,    74,    83,    44,     1,    69,     2,    49,    44,   136,
     167,    45,    85,   145,    46,    47,    86,    90,    73,   124,
     136,     8,    76,    77,    78,    79,    80,    81,    10,   119,
      52,    47,    74,   188,   126,   146,    73,    54,    55,    56,
      14,    15,    11,    16,    17,    18,    19,    20,    21,    57,
     122,   123,    91,    73,   136,   179,    86,   156,   137,   140,
      58,    12,   138,    28,   150,   151,    76,    77,    78,    79,
      80,    81,   177,   155,   191,   192,   178,   153,   123,    59,
     136,   136,   136,   136,   205,    60,   206,    35,   207,   208,
      53,    38,    54,    55,    56,    43,    45,    48,    50,   171,
     147,    70,    51,   176,    57,   187,    74,    54,    55,    56,
      97,    75,    98,   184,    69,    58,   190,    14,    15,    57,
      16,    17,    18,    19,    20,    21,   198,    99,   100,    87,
      58,   101,   102,   103,    59,    88,   104,    89,   105,    95,
      60,   124,   106,    92,    94,    96,   133,   127,    98,    59,
     128,   129,   130,    14,    15,    60,    16,    17,    18,    19,
      20,    21,   131,    99,   100,   132,   141,   101,   102,   103,
     135,   139,   104,   144,   105,    98,   152,   123,   106,   157,
      14,    15,   168,    16,    17,    18,    19,    20,    21,   166,
      99,   100,   170,   175,   101,   102,   103,   172,    98,   104,
     180,   105,   181,    14,    15,   106,    16,    17,    18,    19,
      20,    21,   183,    99,   100,   196,   195,   101,   102,   103,
     197,   199,   104,   200,   105,    98,   201,   202,   106,   154,
      14,    15,   203,    16,    17,    18,    19,    20,    21,     9,
      99,   100,    27,    41,   101,   102,   103,    68,    84,   104,
      93,   105,    98,   121,     0,   106,   165,    14,    15,     0,
      16,    17,    18,    19,    20,    21,     0,    99,   100,     0,
       0,   101,   102,   103,     0,     0,   104,     0,   105,    98,
       0,     0,   106,   185,    14,    15,     0,    16,    17,    18,
      19,    20,    21,     0,    99,   100,     0,     0,   101,   102,
     103,     0,     0,   104,     0,   105,    98,     0,     0,   106,
     209,    14,    15,     0,    16,    17,    18,    19,    20,    21,
       0,    99,   100,     0,     0,   101,   102,   103,     0,     0,
     104,     0,   105,    98,     0,     0,   106,   210,    14,    15,
       0,    16,    17,    18,    19,    20,    21,     0,    99,   100,
       0,     0,   101,   102,   103,     0,    13,   104,     0,   105,
       0,    14,    15,   106,    16,    17,    18,    19,    20,    21,
      13,    76,    77,    78,    79,    80,    81,     0,    16,    17,
      18,    19,    20,    21,   158,   159,   160,   161,   162,   163,
      76,    77,    78,    79,    80,    81,    76,    77,    78,    79,
      80,    81,     0,   204
};

static const yytype_int16 yycheck[] =
{
      45,   129,    11,    12,   109,     3,   166,    23,    37,     4,
      23,   106,    25,    31,    23,    31,    10,    30,    31,    37,
     180,    50,    67,    34,     8,    31,    10,    40,    39,   134,
      32,    37,    32,   128,    35,    36,    36,    82,    51,    37,
     145,     0,    44,    45,    46,    47,    48,    49,     4,    94,
      35,    36,    50,   181,    99,     3,    69,     5,     6,     7,
       8,     9,    33,    11,    12,    13,    14,    15,    16,    17,
      34,    35,    32,    86,   179,   170,    36,    35,    32,   124,
      28,    33,    36,    34,   129,   130,    44,    45,    46,    47,
      48,    49,    32,   138,    25,    26,    36,    34,    35,    47,
     205,   206,   207,   208,   199,    53,   201,     3,   203,   204,
       3,    34,     5,     6,     7,     3,    37,     3,     3,   164,
     129,     3,    31,   168,    17,     3,    50,     5,     6,     7,
       1,     3,     3,   178,    31,    28,   181,     8,     9,    17,
      11,    12,    13,    14,    15,    16,   191,    18,    19,     3,
      28,    22,    23,    24,    47,     3,    27,    31,    29,    32,
      53,    37,    33,    33,    31,    33,     1,    31,     3,    47,
      33,    31,    31,     8,     9,    53,    11,    12,    13,    14,
      15,    16,    35,    18,    19,    31,    35,    22,    23,    24,
      34,    34,    27,     1,    29,     3,     5,    35,    33,    32,
       8,     9,    36,    11,    12,    13,    14,    15,    16,    35,
      18,    19,    33,    33,    22,    23,    24,    21,     3,    27,
      31,    29,    35,     8,     9,    33,    11,    12,    13,    14,
      15,    16,    35,    18,    19,    32,    20,    22,    23,    24,
      32,    51,    27,    34,    29,     3,    33,    35,    33,    34,
       8,     9,    33,    11,    12,    13,    14,    15,    16,     4,
      18,    19,    12,    31,    22,    23,    24,    47,    69,    27,
      86,    29,     3,    96,    -1,    33,    34,     8,     9,    -1,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    -1,
      -1,    22,    23,    24,    -1,    -1,    27,    -1,    29,     3,
      -1,    -1,    33,    34,     8,     9,    -1,    11,    12,    13,
      14,    15,    16,    -1,    18,    19,    -1,    -1,    22,    23,
      24,    -1,    -1,    27,    -1,    29,     3,    -1,    -1,    33,
      34,     8,     9,    -1,    11,    12,    13,    14,    15,    16,
      -1,    18,    19,    -1,    -1,    22,    23,    24,    -1,    -1,
      27,    -1,    29,     3,    -1,    -1,    33,    34,     8,     9,
      -1,    11,    12,    13,    14,    15,    16,    -1,    18,    19,
      -1,    -1,    22,    23,    24,    -1,     3,    27,    -1,    29,
      -1,     8,     9,    33,    11,    12,    13,    14,    15,    16,
       3,    44,    45,    46,    47,    48,    49,    -1,    11,    12,
      13,    14,    15,    16,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    44,    45,    46,    47,
      48,    49,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    55,    56,    57,    10,     4,     0,    57,
       4,    33,    33,     3,     8,     9,    11,    12,    13,    14,
      15,    16,    58,    59,    60,    63,    98,    58,    34,    60,
      63,    64,    65,    98,    98,     3,    61,    62,    34,    98,
      63,    65,    98,     3,    61,    37,    35,    36,     3,    98,
       3,    31,    35,     3,     5,     6,     7,    17,    28,    47,
      53,    89,    90,    91,    92,    93,    95,    97,    62,    31,
       3,    66,    67,    98,    50,     3,    44,    45,    46,    47,
      48,    49,    96,    89,    66,    32,    36,     3,     3,    31,
      89,    32,    33,    67,    31,    32,    33,     1,     3,    18,
      19,    22,    23,    24,    27,    29,    33,    60,    68,    69,
      70,    71,    72,    75,    76,    80,    82,    83,    84,    89,
      94,    68,    34,    35,    37,    85,    89,    31,    33,    31,
      31,    35,    31,     1,    69,    34,    70,    32,    36,    34,
      89,    35,    87,    89,     1,    69,     3,    60,    71,    73,
      89,    89,     5,    34,    34,    89,    35,    32,    38,    39,
      40,    41,    42,    43,    88,    34,    35,    32,    36,    81,
      33,    89,    21,    86,    87,    33,    89,    32,    36,    69,
      31,    35,    77,    35,    89,    34,    87,     3,    71,    74,
      89,    25,    26,    78,    79,    20,    32,    32,    89,    51,
      34,    33,    35,    33,    51,    69,    69,    69,    69,    34,
      34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    65,    65,    66,    66,    66,    67,    68,    68,
      69,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    72,    72,    73,    73,    73,    73,    74,
      74,    75,    75,    76,    77,    77,    78,    79,    79,    80,
      81,    81,    81,    82,    83,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    88,    88,    88,    88,    89,
      89,    89,    89,    89,    89,    90,    91,    92,    93,    94,
      94,    94,    95,    95,    95,    95,    96,    96,    96,    96,
      96,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     5,     2,     1,     2,
       0,     3,     4,     3,     1,     1,     3,     1,     1,     1,
       2,     0,     9,     8,     1,     3,     0,     2,     1,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     9,    11,     1,     1,     1,     0,     1,
       1,     7,    11,     8,     0,     2,     4,     0,     3,     6,
       0,     2,     3,     3,     2,     3,     3,     0,     1,     0,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     6,     4,     0,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 29: /* method_body: error RBRACE  */
#line 190 "parser3.y"
                   { yyerrok; }
#line 1405 "parser3.tab.c"
    break;

  case 32: /* statement_list: error SEMICOLON  */
#line 196 "parser3.y"
                      { yyerrok; }
#line 1411 "parser3.tab.c"
    break;

  case 66: /* block_statement: LBRACE error RBRACE  */
#line 275 "parser3.y"
                          { yyerrok; }
#line 1417 "parser3.tab.c"
    break;


#line 1421 "parser3.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 364 "parser3.y"


void yyerror(const char *s) {
    add_error(yylineno, s);  // Store the error instead of printing immediately
    error_count++;
    // No token skipping; just report the error and continue parsing
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    int result = yyparse();
    print_errors();  // Print all errors at the end
    if (error_count > 0) {
        fprintf(stderr, "Parsing failed with %d errors.\n", error_count);
    } else {
        fprintf(stdout, "Parsing succeeded with no errors.\n");
    }
    return result;
}
