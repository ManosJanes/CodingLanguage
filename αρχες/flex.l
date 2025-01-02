%{
#include "bison.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void yyerror(const char *s);
%}

%option yylineno

%%
"int"             { return INT; }
"char"            { return CHAR; }
"double"          { return DBL; }
"boolean"         { return BOOL; }
"String"          { return STR; }
"public"          { return PUB; }
"private"         { return PRIV; }
"class"           { return CLS; }
"new"             { return NEW; }
"return"          { return RETURN; }
"void"            { return VOID; }
"if"              { return IF; }
"else"            { return ELSE; }
"while"           { return WHILE; }
"do"              { return DO; }
"for"             { return FOR; }
"switch"          { return SWITCH; }
"case"            { return CASE; }
"default"         { return DEFAULT; }
"break"           { return BREAK; }
"true"            { return BOOL_LIT; }
"false"           { return BOOL_LIT; }
"out.print"       { return PRINT; }
"("               { return AR_PAREN; }
")"               { return DE_PAREN; }
"{"               { return AR_AG; }
"}"               { return DE_AG; }
";"               { return ERWT; }
","               { return KOM; }
"="               { return ISON; }
"+"               { return SIN; }
"-"               { return MEION ; }
"=="              { return SINEP; }
"!="              { return INEK; }
"<"               { return MIK; }
">"               { return MEG; }
"<="              { return MIKIS; }
">="              { return MEGIS; }
"&&"              { return AND; }
"||"              { return OR; }
"*"               { return EPI; }
"/"               { return DIA; }
"."               { return TEL; }
":"               { return ANKAT; }

"//".*            { /* Ignore single-line comments */ }
[ \t\n\r]+        { /* Ignore whitespace */ }
"/\\*([^*]|\\*+[^*/])*\\*/"  { /* Ignore multi-line comments */ }
\'([^\\\']|\\.)\'  { yylval.str = strdup(yytext); return CHAR_LIT; }
\"([^\\\"]|\\.)*\" { yylval.str = strdup(yytext); return STR_LIT; }
[0-9]+(\.[0-9]+)?d? { yylval.num = atof(yytext); return NUM; }

[A-Z][A-Za-z0-9_]* { yylval.str = strdup(yytext); return UPPER_ID; }
[a-zA-Z_][A-Za-z0-9_]* { yylval.str = strdup(yytext); return ID; }

.                 { return yytext[0]; }

%%

int yywrap() {
    return 1;
}
