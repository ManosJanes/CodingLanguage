%{
#include "bison.tab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void yyerror(const char *s);
%}

%option yylineno

%%

"public"          { return PUBLIC; }
"private"         { return PRIVATE; }
"class"           { return CLASS; }
"int"             { return INT; }
"char"            { return CHAR; }
"double"          { return DBL; }
"boolean"         { return BOOL; }
"String"          { return STRING; }
"new"             { return NEW; }
"return"          { return RETURN; }
"void"            { return VOID; }
"true"            { return BOOL_LIT; }
"false"           { return BOOL_LIT; }
"do"              { return DO; }
"while"           { return WHILE; }
"for"             { return FOR; }
"if"              { return IF; }
"else"            { return ELSE; }
"switch"          { return SWITCH; }
"case"            { return CASE; }
"default"         { return DEFAULT; }
"out.print"       { return PRINT; }
"break"           { return BREAK; }
"static"          { return STATIC; }
"main"            { return MAIN; }

"+"               { return PLUS; }
"-"               { return MINUS; }
"*"               { return MUL; }
"/"               { return DIV; }

">"               { return '>'; }
"<"               { return '<'; }
"=="              { return EQUALS; }
"!="              { return NOT_EQUALS; }
"&&"              { return AND; }
"||"              { return OR; }

[A-Z][a-zA-Z0-9_]* {
    yylval.str = strdup(yytext);
    return CLASS_ID;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.str = strdup(yytext);
    return ID;
}

\"([^\\\"]|\\.)*\" { yylval.str = strdup(yytext); return STR_LIT; }

\'([^\\\']|\\.)\'  { yylval.str = strdup(yytext); return CHAR_LIT; }

[0-9]+\.[0-9]+d   { yylval.num = atof(yytext); return NUM; }

[0-9]+            { yylval.num = atoi(yytext); return NUM; }

"="               { return '='; }
"."               { return '.'; }
"("               { return '('; }
")"               { return ')'; }
"{"               { return '{'; }
"}"               { return '}'; }
","               { return ','; }
";"               { return ';'; }

"//".*            { /* Ignore single-line comments */ }
"/\\*([^*]|\\*+[^*/])*\\*/" { /* Ignore multi-line comments */ }

[ \t\n\r]+        { /* Ignore whitespace */ }

<<EOF>>           { return 0; }

. {
    fprintf(stderr, "Error: Unrecognized character '%s' at line %d\n", yytext, yylineno);
    return ERROR;
}

%%

int yywrap() {
    return 1;
}
