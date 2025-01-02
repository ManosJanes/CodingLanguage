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
#line 1 "bison1.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to add an error to the list
void add_error(int line, const char *message) {
    Error *new_error = (Error *)malloc(sizeof(Error));
    new_error->line = line;
    new_error->message = strdup(message);
    new_error->next = error_list;
    error_list = new_error;
}

// Function to write errors to a file
void write_errors_to_file() {
    FILE *file = fopen("errors.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open errors.txt for writing\n");
        return;
    }
    Error *current = error_list;
    while (current != NULL) {
        fprintf(file, "Σφάλμα: %s στη γραμμή %d\n", current->message, current->line);
        current = current->next;
    }
    fclose(file);
}

// Function to clear the error list
void clear_errors() {
    Error *current = error_list;
    while (current != NULL) {
        Error *next = current->next;
        free(current->message);
        free(current);
        current = next;
    }
    error_list = NULL;
}

#line 130 "bison1.tab.c"

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

#include "bison1.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR_LIT = 3,                   /* CHAR_LIT  */
  YYSYMBOL_STR_LIT = 4,                    /* STR_LIT  */
  YYSYMBOL_NUM = 5,                        /* NUM  */
  YYSYMBOL_UPPER_ID = 6,                   /* UPPER_ID  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_DBL = 10,                       /* DBL  */
  YYSYMBOL_BOOL = 11,                      /* BOOL  */
  YYSYMBOL_STR = 12,                       /* STR  */
  YYSYMBOL_PUB = 13,                       /* PUB  */
  YYSYMBOL_PRIV = 14,                      /* PRIV  */
  YYSYMBOL_CLS = 15,                       /* CLS  */
  YYSYMBOL_NEW = 16,                       /* NEW  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_VOID = 18,                      /* VOID  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_SWITCH = 24,                    /* SWITCH  */
  YYSYMBOL_CASE = 25,                      /* CASE  */
  YYSYMBOL_DEFAULT = 26,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 27,                     /* BREAK  */
  YYSYMBOL_BOOL_LIT = 28,                  /* BOOL_LIT  */
  YYSYMBOL_PRINT = 29,                     /* PRINT  */
  YYSYMBOL_AR_PAREN = 30,                  /* AR_PAREN  */
  YYSYMBOL_DE_PAREN = 31,                  /* DE_PAREN  */
  YYSYMBOL_AR_AG = 32,                     /* AR_AG  */
  YYSYMBOL_DE_AG = 33,                     /* DE_AG  */
  YYSYMBOL_ERWT = 34,                      /* ERWT  */
  YYSYMBOL_KOM = 35,                       /* KOM  */
  YYSYMBOL_ISON = 36,                      /* ISON  */
  YYSYMBOL_SIN = 37,                       /* SIN  */
  YYSYMBOL_MEION = 38,                     /* MEION  */
  YYSYMBOL_SINEP = 39,                     /* SINEP  */
  YYSYMBOL_INEK = 40,                      /* INEK  */
  YYSYMBOL_MIK = 41,                       /* MIK  */
  YYSYMBOL_MEG = 42,                       /* MEG  */
  YYSYMBOL_MIKIS = 43,                     /* MIKIS  */
  YYSYMBOL_MEGIS = 44,                     /* MEGIS  */
  YYSYMBOL_AND = 45,                       /* AND  */
  YYSYMBOL_OR = 46,                        /* OR  */
  YYSYMBOL_EPI = 47,                       /* EPI  */
  YYSYMBOL_DIA = 48,                       /* DIA  */
  YYSYMBOL_TEL = 49,                       /* TEL  */
  YYSYMBOL_ANKAT = 50,                     /* ANKAT  */
  YYSYMBOL_LOWER_THAN_ELSE = 51,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_52_ = 52,                       /* "!"  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_prog = 54,                      /* prog  */
  YYSYMBOL_class_decl_list = 55,           /* class_decl_list  */
  YYSYMBOL_class_decl = 56,                /* class_decl  */
  YYSYMBOL_class_body = 57,                /* class_body  */
  YYSYMBOL_var_decl_list = 58,             /* var_decl_list  */
  YYSYMBOL_var_decl = 59,                  /* var_decl  */
  YYSYMBOL_var_declrs = 60,                /* var_declrs  */
  YYSYMBOL_var_declr = 61,                 /* var_declr  */
  YYSYMBOL_access_mod = 62,                /* access_mod  */
  YYSYMBOL_method_decl_list = 63,          /* method_decl_list  */
  YYSYMBOL_method_decl = 64,               /* method_decl  */
  YYSYMBOL_param_list = 65,                /* param_list  */
  YYSYMBOL_param = 66,                     /* param  */
  YYSYMBOL_method = 67,                    /* method  */
  YYSYMBOL_stmt_list = 68,                 /* stmt_list  */
  YYSYMBOL_stmt = 69,                      /* stmt  */
  YYSYMBOL_assign_stmt = 70,               /* assign_stmt  */
  YYSYMBOL_loop_stmt = 71,                 /* loop_stmt  */
  YYSYMBOL_for_1 = 72,                     /* for_1  */
  YYSYMBOL_for_2 = 73,                     /* for_2  */
  YYSYMBOL_control_stmt = 74,              /* control_stmt  */
  YYSYMBOL_switch_stmt = 75,               /* switch_stmt  */
  YYSYMBOL_case_clauses = 76,              /* case_clauses  */
  YYSYMBOL_case_clause = 77,               /* case_clause  */
  YYSYMBOL_default_clause_opt = 78,        /* default_clause_opt  */
  YYSYMBOL_print_stmt = 79,                /* print_stmt  */
  YYSYMBOL_print_arg_list = 80,            /* print_arg_list  */
  YYSYMBOL_return_stmt = 81,               /* return_stmt  */
  YYSYMBOL_break_stmt = 82,                /* break_stmt  */
  YYSYMBOL_block_stmt = 83,                /* block_stmt  */
  YYSYMBOL_expr_opt = 84,                  /* expr_opt  */
  YYSYMBOL_condition = 85,                 /* condition  */
  YYSYMBOL_condition_1 = 86,               /* condition_1  */
  YYSYMBOL_binary_expr = 87,               /* binary_expr  */
  YYSYMBOL_unary_expr = 88,                /* unary_expr  */
  YYSYMBOL_expr = 89,                      /* expr  */
  YYSYMBOL_rel_op = 90,                    /* rel_op  */
  YYSYMBOL_method_call = 91,               /* method_call  */
  YYSYMBOL_obj_create = 92,                /* obj_create  */
  YYSYMBOL_arg_list = 93,                  /* arg_list  */
  YYSYMBOL_literal = 94,                   /* literal  */
  YYSYMBOL_binary_op = 95,                 /* binary_op  */
  YYSYMBOL_unary_op = 96,                  /* unary_op  */
  YYSYMBOL_data_type = 97                  /* data_type  */
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
#define YYLAST   460

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   131,   131,   135,   136,   140,   141,   145,   149,   150,
     151,   155,   156,   160,   161,   165,   166,   170,   171,   175,
     176,   177,   181,   182,   186,   187,   188,   192,   196,   200,
     201,   202,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   219,   223,   224,   228,   229,   230,   231,   235,
     236,   237,   241,   242,   246,   250,   251,   255,   259,   260,
     264,   268,   269,   270,   274,   278,   282,   286,   287,   291,
     292,   296,   297,   301,   305,   309,   310,   311,   312,   313,
     314,   318,   319,   320,   321,   322,   323,   327,   331,   335,
     336,   337,   341,   342,   343,   344,   348,   349,   350,   351,
     352,   353,   357,   358,   362,   363,   364,   365,   366,   367,
     368
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
  "\"end of file\"", "error", "\"invalid token\"", "CHAR_LIT", "STR_LIT",
  "NUM", "UPPER_ID", "ID", "INT", "CHAR", "DBL", "BOOL", "STR", "PUB",
  "PRIV", "CLS", "NEW", "RETURN", "VOID", "IF", "ELSE", "WHILE", "DO",
  "FOR", "SWITCH", "CASE", "DEFAULT", "BREAK", "BOOL_LIT", "PRINT",
  "AR_PAREN", "DE_PAREN", "AR_AG", "DE_AG", "ERWT", "KOM", "ISON", "SIN",
  "MEION", "SINEP", "INEK", "MIK", "MEG", "MIKIS", "MEGIS", "AND", "OR",
  "EPI", "DIA", "TEL", "ANKAT", "LOWER_THAN_ELSE", "\"!\"", "$accept",
  "prog", "class_decl_list", "class_decl", "class_body", "var_decl_list",
  "var_decl", "var_declrs", "var_declr", "access_mod", "method_decl_list",
  "method_decl", "param_list", "param", "method", "stmt_list", "stmt",
  "assign_stmt", "loop_stmt", "for_1", "for_2", "control_stmt",
  "switch_stmt", "case_clauses", "case_clause", "default_clause_opt",
  "print_stmt", "print_arg_list", "return_stmt", "break_stmt",
  "block_stmt", "expr_opt", "condition", "condition_1", "binary_expr",
  "unary_expr", "expr", "rel_op", "method_call", "obj_create", "arg_list",
  "literal", "binary_op", "unary_op", "data_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-111)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      32,    -6,    13,    29,    32,  -141,    49,    26,  -141,  -141,
      27,   430,   430,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,    43,   430,  -141,   442,    71,    53,  -141,  -141,
     442,   430,  -141,    89,    71,    62,    46,  -141,  -141,    97,
     442,  -141,   108,   -23,    50,    35,  -141,    71,     0,   115,
      94,   442,  -141,  -141,  -141,  -141,    76,   121,  -141,  -141,
    -141,  -141,  -141,   100,  -141,  -141,  -141,    35,  -141,   442,
      99,    17,  -141,   124,   126,   104,  -141,  -141,  -141,  -141,
    -141,  -141,    35,   100,    25,   103,   442,  -141,   109,   110,
     100,   111,   202,  -141,    35,  -141,   202,  -141,   106,    35,
     122,   119,   123,   133,   130,   139,   202,  -141,   145,   229,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,   100,
      33,   146,    35,   156,   100,    35,   202,    98,    35,  -141,
     187,   256,  -141,  -141,  -141,    35,  -141,   100,  -141,   164,
     388,   283,     8,  -141,  -141,   162,   100,   -21,   170,  -141,
     100,   174,  -141,  -141,  -141,  -141,  -141,  -141,    35,   196,
      35,   186,    35,    44,   202,   100,   192,  -141,   189,  -141,
     100,   193,    35,   310,    35,   116,    63,  -141,   100,   208,
     201,   -18,  -141,   213,   100,    35,   183,  -141,   212,   217,
     216,   222,    24,   202,  -141,   202,  -141,   202,   148,   337,
     364,   391,   175,  -141,  -141
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     0,     0,     1,     4,
       0,    10,    10,   110,   104,   105,   106,   107,   108,    17,
      18,   109,     0,    21,     8,     0,     0,     0,     6,     9,
       0,     7,    19,     0,     0,    15,     0,    13,     5,     0,
       0,    20,     0,    15,     0,     0,    11,     0,    15,     0,
       0,    26,    12,    93,    94,    92,    76,     0,    95,   102,
     103,    77,    78,    16,    79,    80,    75,     0,    14,    26,
       0,     0,    24,     0,     0,     0,    96,    97,   100,   101,
      98,    99,     0,    74,     0,     0,     0,    27,     0,     0,
      73,     0,     0,    25,    89,    88,     0,    41,   110,    67,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
      29,    32,    33,    34,    37,    36,    38,    35,    39,    90,
       0,     0,     0,     0,    68,     0,     0,    48,     0,    65,
       0,     0,    23,    30,    87,     0,    22,    42,    64,     0,
      70,     0,    76,    45,    46,     0,    47,     0,    61,    66,
      91,     0,    83,    84,    81,    82,    85,    86,     0,     0,
      71,     0,     0,     0,     0,    69,     0,    72,     0,    55,
      62,     0,     0,     0,     0,    51,    58,    60,    63,    52,
       0,    76,    49,     0,    50,     0,     0,    56,     0,     0,
       0,     0,     0,     0,    54,     0,    43,     0,     0,     0,
       0,     0,     0,    53,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,   251,   247,  -141,    -9,     7,   224,    12,
    -141,   241,   191,   190,   181,   -98,  -108,  -122,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -140,  -141,  -141,  -141,   -45,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,   -19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,    22,    23,   107,    36,    37,    25,
      31,    32,    71,    72,   108,   109,   110,   111,   112,   145,
     183,   113,   114,   176,   187,   188,   115,   163,   116,   117,
     118,   123,   139,   168,    61,    62,   140,   158,    64,    65,
     120,    66,    82,    67,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,   133,    24,    24,    33,   144,    34,    51,   131,     6,
     161,    39,    42,    45,    29,  -110,    76,    77,   122,     7,
     167,    49,    83,   133,    78,    79,    80,    81,   141,     8,
      69,    74,    73,   133,   180,    30,    45,    90,    53,    54,
      55,    44,    56,    40,   122,     1,    44,     2,    85,   119,
      73,    57,    86,   182,   124,    10,    91,    74,    11,    12,
      86,    76,    77,    58,   134,   133,   173,    73,   135,    78,
      79,    80,    81,    59,   198,   171,    28,   137,    35,   172,
      46,    47,   146,   147,    52,    47,    38,    60,   185,   186,
     150,   133,   133,   133,   133,   199,    43,   200,    45,   201,
     202,    53,    54,    55,    48,   142,    14,    15,    16,    17,
      18,    19,    20,   165,    57,    50,    21,   170,   143,    53,
      54,    55,    70,   181,    51,    74,    58,   178,    75,    69,
     184,    87,    57,    88,    89,    92,    59,    76,    77,    94,
     192,    95,   122,    96,    58,    78,    79,    80,    81,    97,
      60,   126,   125,   127,    59,    98,    14,    15,    16,    17,
      18,    19,    20,   128,   129,    99,    21,   100,    60,   130,
     101,   102,   103,   -31,   -31,   104,    97,   105,   132,   136,
     106,   -31,    98,    14,    15,    16,    17,    18,    19,    20,
     138,   148,    99,    21,   100,   151,   160,   101,   102,   103,
     -57,   -57,   104,    97,   105,   162,   164,   106,   -57,    98,
      14,    15,    16,    17,    18,    19,    20,   166,   169,    99,
      21,   100,   174,   175,   101,   102,   103,   177,   189,   104,
      97,   105,   190,   193,   106,   -31,    98,    14,    15,    16,
      17,    18,    19,    20,   191,   194,    99,    21,   100,   195,
     196,   101,   102,   103,   197,     9,   104,    97,   105,    27,
      84,   106,   -28,    98,    14,    15,    16,    17,    18,    19,
      20,    68,    41,    99,    21,   100,    93,   121,   101,   102,
     103,     0,     0,   104,    97,   105,     0,     0,   106,   149,
      98,    14,    15,    16,    17,    18,    19,    20,     0,     0,
      99,    21,   100,     0,     0,   101,   102,   103,     0,     0,
     104,    97,   105,     0,     0,   106,   159,    98,    14,    15,
      16,    17,    18,    19,    20,     0,     0,    99,    21,   100,
       0,     0,   101,   102,   103,     0,     0,   104,    97,   105,
       0,     0,   106,   179,    98,    14,    15,    16,    17,    18,
      19,    20,     0,     0,    99,    21,   100,     0,     0,   101,
     102,   103,     0,     0,   104,    97,   105,     0,     0,   106,
     -59,    98,    14,    15,    16,    17,    18,    19,    20,     0,
       0,    99,    21,   100,     0,     0,   101,   102,   103,     0,
       0,   104,    97,   105,     0,     0,   106,   203,    98,    14,
      15,    16,    17,    18,    19,    20,     0,     0,    99,    21,
     100,     0,     0,   101,   102,   103,     0,     0,   104,     0,
     105,     0,     0,   106,   204,    76,    77,   152,   153,   154,
     155,   156,   157,    78,    79,    80,    81,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,    21,    13,
      14,    15,    16,    17,    18,     0,     0,     0,     0,     0,
      21
};

static const yytype_int16 yycheck[] =
{
      45,   109,    11,    12,    23,   127,    25,    30,   106,    15,
      31,    30,    31,    36,    23,     7,    37,    38,    36,     6,
     160,    40,    67,   131,    45,    46,    47,    48,   126,     0,
      30,    49,    51,   141,   174,    23,    36,    82,     3,     4,
       5,    34,     7,    31,    36,    13,    39,    15,    31,    94,
      69,    16,    35,   175,    99,     6,    31,    49,    32,    32,
      35,    37,    38,    28,    31,   173,   164,    86,    35,    45,
      46,    47,    48,    38,    50,    31,    33,   122,     7,    35,
      34,    35,   127,   128,    34,    35,    33,    52,    25,    26,
     135,   199,   200,   201,   202,   193,     7,   195,    36,   197,
     198,     3,     4,     5,     7,     7,     8,     9,    10,    11,
      12,    13,    14,   158,    16,     7,    18,   162,   127,     3,
       4,     5,     7,     7,    30,    49,    28,   172,     7,    30,
     175,     7,    16,     7,    30,    32,    38,    37,    38,    30,
     185,    31,    36,    32,    28,    45,    46,    47,    48,     1,
      52,    32,    30,    30,    38,     7,     8,     9,    10,    11,
      12,    13,    14,    30,    34,    17,    18,    19,    52,    30,
      22,    23,    24,    25,    26,    27,     1,    29,    33,    33,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      34,     4,    17,    18,    19,    31,    34,    22,    23,    24,
      25,    26,    27,     1,    29,    35,    32,    32,    33,     7,
       8,     9,    10,    11,    12,    13,    14,    21,    32,    17,
      18,    19,    30,    34,    22,    23,    24,    34,    20,    27,
       1,    29,    31,    50,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    31,    33,    17,    18,    19,    32,
      34,    22,    23,    24,    32,     4,    27,     1,    29,    12,
      69,    32,    33,     7,     8,     9,    10,    11,    12,    13,
      14,    47,    31,    17,    18,    19,    86,    96,    22,    23,
      24,    -1,    -1,    27,     1,    29,    -1,    -1,    32,    33,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      17,    18,    19,    -1,    -1,    22,    23,    24,    -1,    -1,
      27,     1,    29,    -1,    -1,    32,    33,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      -1,    -1,    22,    23,    24,    -1,    -1,    27,     1,    29,
      -1,    -1,    32,    33,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    17,    18,    19,    -1,    -1,    22,
      23,    24,    -1,    -1,    27,     1,    29,    -1,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    17,    18,    19,    -1,    -1,    22,    23,    24,    -1,
      -1,    27,     1,    29,    -1,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    17,    18,
      19,    -1,    -1,    22,    23,    24,    -1,    -1,    27,    -1,
      29,    -1,    -1,    32,    33,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    18,     7,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      18
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    15,    54,    55,    56,    15,     6,     0,    56,
       6,    32,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    18,    57,    58,    59,    62,    97,    57,    33,    59,
      62,    63,    64,    97,    97,     7,    60,    61,    33,    97,
      62,    64,    97,     7,    60,    36,    34,    35,     7,    97,
       7,    30,    34,     3,     4,     5,     7,    16,    28,    38,
      52,    87,    88,    89,    91,    92,    94,    96,    61,    30,
       7,    65,    66,    97,    49,     7,    37,    38,    45,    46,
      47,    48,    95,    89,    65,    31,    35,     7,     7,    30,
      89,    31,    32,    66,    30,    31,    32,     1,     7,    17,
      19,    22,    23,    24,    27,    29,    32,    59,    67,    68,
      69,    70,    71,    74,    75,    79,    81,    82,    83,    89,
      93,    67,    36,    84,    89,    30,    32,    30,    30,    34,
      30,    68,    33,    69,    31,    35,    33,    89,    34,    85,
      89,    68,     7,    59,    70,    72,    89,    89,     4,    33,
      89,    31,    39,    40,    41,    42,    43,    44,    90,    33,
      34,    31,    35,    80,    32,    89,    21,    85,    86,    32,
      89,    31,    35,    68,    30,    34,    76,    34,    89,    33,
      85,     7,    70,    73,    89,    25,    26,    77,    78,    20,
      31,    31,    89,    50,    33,    32,    34,    32,    50,    68,
      68,    68,    68,    33,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    58,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    63,    64,    64,    65,    65,    65,    66,    67,    68,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    71,    71,    72,    72,    72,    72,    73,
      73,    73,    74,    74,    75,    76,    76,    77,    78,    78,
      79,    80,    80,    80,    81,    82,    83,    84,    84,    85,
      85,    86,    86,    87,    88,    89,    89,    89,    89,    89,
      89,    90,    90,    90,    90,    90,    90,    91,    92,    93,
      93,    93,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    96,    96,    97,    97,    97,    97,    97,    97,
      97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     5,     2,     1,     2,
       0,     3,     4,     1,     3,     1,     3,     1,     1,     1,
       2,     0,     9,     8,     1,     3,     0,     2,     1,     1,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     9,    11,     1,     1,     1,     0,     1,
       1,     0,     7,    11,     8,     0,     2,     4,     0,     3,
       6,     0,     2,     3,     3,     2,     3,     0,     1,     3,
       1,     0,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     6,     4,     0,
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
  case 41: /* stmt: error  */
#line 215 "bison1.y"
            { add_error(yylineno, "syntax error"); yyerrok; }
#line 1412 "bison1.tab.c"
    break;


#line 1416 "bison1.tab.c"

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

#line 371 "bison1.y"


void yyerror(const char *s) {
    add_error(yylineno, s);  // Store the error instead of printing immediately
    error_count++;
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Δεν μπόρεσα να ανοίξω το %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    int result = yyparse();
    write_errors_to_file();  // Write all errors to file at the end
    if (error_count > 0) {
        fprintf(stderr, "Η ανάλυση απέτυχε με %d σφάλματα.\n", error_count);
    } else {
        fprintf(stdout, "Η ανάλυση ολοκληρώθηκε με επιτυχία χωρίς σφάλματα.\n");
    }
    clear_errors();  // Clear errors at the end
    return result;
}
