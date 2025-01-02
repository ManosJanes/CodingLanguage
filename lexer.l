%{
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"


void token_print(int token_id);
extern YYSTYPE yylval;
%}

%option noyywrap
%option yylineno

%%
"public"          {token_print(T_PUBLIC); return T_PUBLIC; }
"private"         {token_print(T_PRIVATE); return T_PRIVATE; }
"class"           {token_print(T_CLASS); return T_CLASS; }
"int"             {token_print(T_INT); return T_INT; }
"char"            {token_print(T_CHAR); return T_CHAR; }
"double"          {token_print(T_DOUBLE); return T_DOUBLE; }
"boolean"         {token_print(T_BOOLEAN); return T_BOOLEAN; }
"String"          {token_print(T_STRING); return T_STRING; }
"new"             {token_print(T_NEW); return T_NEW; }
"return"          {token_print(T_RETURN); return T_RETURN; }
"void"            {token_print(T_VOID); return T_VOID; }
"if"              {token_print(T_IF); return T_IF; }
"else"            {token_print(T_ELSE); return T_ELSE; }
"while"           {token_print(T_WHILE); return T_WHILE; }
"do"              {token_print(T_DO); return T_DO; }
"for"             {token_print(T_FOR); return T_FOR; }
"switch"          {token_print(T_SWITCH); return T_SWITCH; }
"case"            {token_print(T_CASE); return T_CASE; }
"default"         {token_print(T_DEFAULT); return T_DEFAULT; }
"break"           {token_print(T_BREAK); return T_BREAK; }
"true"            {token_print(T_TRUE); return T_TRUE; }
"false"           {token_print(T_FALSE); return T_FALSE; }

[a-zA-Z_][a-zA-Z0-9_]*  { token_print(IDENTIFIER); yylval.stringValue = strdup(yytext); return IDENTIFIER; }

"+"|"-"|"*"|"/"     { token_print(T_MATHOP); }
 ">"|"<"|"=="|"!="    {token_print(T_COMPOP); return T_COMPOP; }
"&&"|"||"     {token_print(T_LOGICOP); return T_LOGICOP; }    



"{"        { token_print(T_LBRACE); return T_LBRACE; }   
"}"        { token_print(T_RBRACE);return T_RBRACE; }   
"["        { token_print(T_LBRACKET);return T_LBRACKET; } 
"]"        { token_print(T_RBRACKET);return T_RBRACKET; }
"("        { token_print(T_LPAREN);return T_LPAREN; }   
")"        { token_print(T_RPAREN);return T_RPAREN; }   
";"        { token_print(T_SEMICOLON);return T_SEMICOLON; } 
","        { token_print(T_COMMA);return T_COMMA; }        
"?"        { token_print(T_QUESTIONMARK); return T_QUESTIONMARK; }


[0-9]+                { token_print(INT_LITERAL); yylval.intValue = atoi(yytext); return INT_LITERAL; }
[0-9]+"\\."[0-9]*"d"    { token_print(DOUBLE_LITERAL); yylval.doubleValue = atof(yytext); return DOUBLE_LITERAL; }
\'([^'\n]|\\.)\'      { token_print(CHAR_LITERAL); yylval.charValue = yytext[1]; return CHAR_LITERAL; }
\"(\\.|[^\\"\n])*\"   { token_print(STRING_LITERAL); yylval.stringValue = strdup(yytext); return STRING_LITERAL; }

 




[ \t\r\n]+                              {/* αγνόησε whitespace */}
"//".*                                  {/* Ignore single-line comments */}
"/*"([^*]|\*+[^/])*\*+"/"               {/* Ignore multi-line comments */}

.                           { /* Ignore any other characters */ }




<<EOF>>          { return 0; } 
%%


void token_print(int token_id) {
    printf("Found token %s (%d) at line %d\n", yytext, token_id, yylineno );
}
