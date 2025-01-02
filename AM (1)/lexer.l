%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void enter_scope();
extern void exit_scope();
extern void add_symbol(char *name, int is_method);
extern int check_symbol(char *name, int is_method);
extern void yyerror_with_expected(const char *s, const char *expected);
%}

%option yylineno

%%
"public"          { return PUBLIC; }
"private"         { return PRIVATE; }
"class"           { return CLASS; }
"int"             { return INT; }
"char"            { return CHAR; }
"double"          { return DOUBLE; }
"boolean"         { return BOOLEAN; }
"String"          { return STRING; }
"void"            { return VOID; }
"new"             { return NEW; }
"return"          { return RETURN; }
"if"              { return IF; }
"else"            { return ELSE; }
"while"           { return WHILE; }
"do"              { return DO; }
"for"             { return FOR; }
"switch"          { return SWITCH; }
"case"            { return CASE; }
"default"         { return DEFAULT; }
"break"           { return BREAK; }
"true"            { return BOOLEAN_LITERAL; }
"false"           { return BOOLEAN_LITERAL; }
"out.print"       { return OUT_PRINT; }
"then"            { return THEN; }

[ \t\n\r]+        { /* Ignore whitespace */ }
"//".*            { /* Ignore single-line comments */ }
"/\\*([^*]|\\*+[^*/])*\\*/"  { /* Ignore multi-line comments */ }

"("               { return LPAREN; }
")"               { return RPAREN; }
"{"               { return LBRACE; }
"}"               { return RBRACE; }
";"               { return SEMICOLON; }
","               { return COMMA; }
"="               { return ASSIGN; }
"=="              { return EQ; }
"!="              { return NEQ; }
"<"               { return LT; }
">"               { return GT; }
"<="              { return LE; }
">="              { return GE; }
"&&"              { return AND; }
"||"              { return OR; }
"+"               { return PLUS; }
"-"               { return MINUS; }
"*"               { return MUL; }
"/"               { return DIV; }
"."               { return DOT; }
":"               { return COLON; } 

\"([^\\\"]|\\.)*\" { yylval.str = strdup(yytext); return STRING_LITERAL; }
\'([^\\\']|\\.)\'  { yylval.str = strdup(yytext); return CHAR_LITERAL; }
[0-9]+(\.[0-9]+)?d? { yylval.num = atof(yytext); return NUMBER; }

[A-Z][A-Za-z0-9_]* { yylval.str = strdup(yytext); return CAPITALIZED_IDENTIFIER; }
[a-zA-Z_][A-Za-z0-9_]* { yylval.str = strdup(yytext); return IDENTIFIER; }

.                 { return yytext[0]; }

%%

int yywrap() {
    return 1;
}