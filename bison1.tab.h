/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BISON1_TAB_H_INCLUDED
# define YY_YY_BISON1_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHAR_LIT = 258,                /* CHAR_LIT  */
    STR_LIT = 259,                 /* STR_LIT  */
    NUM = 260,                     /* NUM  */
    UPPER_ID = 261,                /* UPPER_ID  */
    ID = 262,                      /* ID  */
    INT = 263,                     /* INT  */
    CHAR = 264,                    /* CHAR  */
    DBL = 265,                     /* DBL  */
    BOOL = 266,                    /* BOOL  */
    STR = 267,                     /* STR  */
    PUB = 268,                     /* PUB  */
    PRIV = 269,                    /* PRIV  */
    CLS = 270,                     /* CLS  */
    NEW = 271,                     /* NEW  */
    RETURN = 272,                  /* RETURN  */
    VOID = 273,                    /* VOID  */
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    WHILE = 276,                   /* WHILE  */
    DO = 277,                      /* DO  */
    FOR = 278,                     /* FOR  */
    SWITCH = 279,                  /* SWITCH  */
    CASE = 280,                    /* CASE  */
    DEFAULT = 281,                 /* DEFAULT  */
    BREAK = 282,                   /* BREAK  */
    BOOL_LIT = 283,                /* BOOL_LIT  */
    PRINT = 284,                   /* PRINT  */
    AR_PAREN = 285,                /* AR_PAREN  */
    DE_PAREN = 286,                /* DE_PAREN  */
    AR_AG = 287,                   /* AR_AG  */
    DE_AG = 288,                   /* DE_AG  */
    ERWT = 289,                    /* ERWT  */
    KOM = 290,                     /* KOM  */
    ISON = 291,                    /* ISON  */
    SIN = 292,                     /* SIN  */
    MEION = 293,                   /* MEION  */
    SINEP = 294,                   /* SINEP  */
    INEK = 295,                    /* INEK  */
    MIK = 296,                     /* MIK  */
    MEG = 297,                     /* MEG  */
    MIKIS = 298,                   /* MIKIS  */
    MEGIS = 299,                   /* MEGIS  */
    AND = 300,                     /* AND  */
    OR = 301,                      /* OR  */
    EPI = 302,                     /* EPI  */
    DIA = 303,                     /* DIA  */
    TEL = 304,                     /* TEL  */
    ANKAT = 305,                   /* ANKAT  */
    LOWER_THAN_ELSE = 306          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 60 "bison1.y"

    char *str;
    double num;

#line 120 "bison1.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BISON1_TAB_H_INCLUDED  */
