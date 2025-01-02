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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    CAPITALIZED_IDENTIFIER = 259,  /* CAPITALIZED_IDENTIFIER  */
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    CHAR_LITERAL = 261,            /* CHAR_LITERAL  */
    NUMBER = 262,                  /* NUMBER  */
    PUBLIC = 263,                  /* PUBLIC  */
    PRIVATE = 264,                 /* PRIVATE  */
    CLASS = 265,                   /* CLASS  */
    INT = 266,                     /* INT  */
    CHAR = 267,                    /* CHAR  */
    DOUBLE = 268,                  /* DOUBLE  */
    BOOLEAN = 269,                 /* BOOLEAN  */
    STRING = 270,                  /* STRING  */
    VOID = 271,                    /* VOID  */
    NEW = 272,                     /* NEW  */
    RETURN = 273,                  /* RETURN  */
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    WHILE = 276,                   /* WHILE  */
    DO = 277,                      /* DO  */
    FOR = 278,                     /* FOR  */
    SWITCH = 279,                  /* SWITCH  */
    CASE = 280,                    /* CASE  */
    DEFAULT = 281,                 /* DEFAULT  */
    BREAK = 282,                   /* BREAK  */
    BOOLEAN_LITERAL = 283,         /* BOOLEAN_LITERAL  */
    OUT_PRINT = 284,               /* OUT_PRINT  */
    THEN = 285,                    /* THEN  */
    LPAREN = 286,                  /* LPAREN  */
    RPAREN = 287,                  /* RPAREN  */
    LBRACE = 288,                  /* LBRACE  */
    RBRACE = 289,                  /* RBRACE  */
    SEMICOLON = 290,               /* SEMICOLON  */
    COMMA = 291,                   /* COMMA  */
    ASSIGN = 292,                  /* ASSIGN  */
    EQ = 293,                      /* EQ  */
    NEQ = 294,                     /* NEQ  */
    LT = 295,                      /* LT  */
    GT = 296,                      /* GT  */
    LE = 297,                      /* LE  */
    GE = 298,                      /* GE  */
    AND = 299,                     /* AND  */
    OR = 300,                      /* OR  */
    PLUS = 301,                    /* PLUS  */
    MINUS = 302,                   /* MINUS  */
    MUL = 303,                     /* MUL  */
    DIV = 304,                     /* DIV  */
    DOT = 305,                     /* DOT  */
    COLON = 306,                   /* COLON  */
    LOWER_THAN_ELSE = 307          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

    char *str;
    double num;

#line 121 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
