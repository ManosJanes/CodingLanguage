%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YYDEBUG 1
extern int yydebug;
extern FILE *yyin;
extern int yylineno;
extern char *yytext;
extern int yylex();
void yyerror(const char *s);
%}

%union {
    double num;
    char *str;
}

%token <num> NUM
%token <str> CHAR_LIT
%token <str> STR_LIT
%token BOOL_LIT
%token <str> ID
%token <str> CLASS_ID
%token CLASS PUBLIC PRIVATE INT CHAR DBL BOOL STRING NEW RETURN VOID DO WHILE FOR IF ELSE SWITCH CASE DEFAULT PRINT BREAK STATIC MAIN
%token EQUALS NOT_EQUALS AND OR
%token PLUS MINUS MUL DIV
%token ERROR

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left OR
%left AND
%left EQUALS NOT_EQUALS
%left '<' '>'
%left PLUS MINUS
%left MUL DIV
%right UMINUS  /* Unary minus */

%start prog

%%

prog
    : class_list
    ;

class_list
    : class_decl
    | class_list class_decl
    ;

class_decl
    : PUBLIC CLASS CLASS_ID '{' class_body '}'
    | CLASS CLASS_ID '{' class_body '}'
    ;

class_body
    : var_decl_list method_decl_list
    ;

var_decl_list
    : var_decl
    | var_decl_list var_decl
    | /* empty */
    ;

var_decl
    : data_type var_declrs ';'
    | access_mod data_type var_declrs ';'
    ;

var_declrs
    : var_declr
    | var_declrs ',' var_declr
    ;

var_declr
    : ID
    | ID '=' expr
    ;

access_mod
    : PUBLIC
    | PRIVATE
    ;

data_type
    : INT
    | CHAR
    | DBL
    | BOOL
    | STRING
    | CLASS_ID  /* Custom class types */
    ;

method_decl_list
    : method_decl
    | method_decl_list method_decl
    | /* empty */
    ;

method_decl
    : access_mod STATIC return_type ID '(' param_list ')' '{' method_body '}'
    | access_mod return_type ID '(' param_list ')' '{' method_body '}'
    | return_type ID '(' param_list ')' '{' method_body '}'
    | access_mod STATIC return_type MAIN '(' ')' '{' method_body '}'
    ;

return_type
    : data_type
    | VOID
    ;

param_list
    : param
    | param_list ',' param
    | /* empty */
    ;

param
    : data_type ID
    ;

method_body
    : statement_blocks
    ;

statement_blocks
    : statement_blocks stmt
    | statement_blocks var_decl
    | /* empty */
    ;

stmt
    : assign_stmt
    | method_call ';'
    | method_call_stmt
    | loop_stmt
    | control_stmt
    | print_stmt
    | return_stmt
    | break_stmt
    ;

assign_stmt
    : ID '=' expr ';'
    ;

method_call_stmt
    : expr '.' ID '(' arg_list ')' ';'
    ;

condition_opt
    : condition
    | /* empty */
    ;


for_expr_opt
    : for_expr
    | /* empty */
    ;

for_init
    : var_decl
    | assign_stmt
    | expr
    | /* empty */
    ;

loop_stmt
    : DO block_stmt WHILE '(' condition ')' ';'
    | FOR '(' for_init ';' condition_opt ';' for_expr_opt ')' block_stmt
    ;

control_stmt
    : IF '(' condition ')' block_stmt else_if_list else_block %prec LOWER_THAN_ELSE
    | SWITCH '(' expr ')' '{' case_clauses default_clause_opt '}'
    ;

case_clauses
    : /* empty */
    | case_clauses case_clause
    ;

case_clause
    : CASE expr ':' statement_blocks
    ;


default_clause_opt
    : /* empty */
    | DEFAULT ':' statement_blocks
    ;

else_if_list
    : /* empty */
    | else_if_list ELSE IF '(' condition ')' block_stmt
    ;

else_block
    : /* empty */
    | ELSE block_stmt
    ;

print_stmt
    : PRINT '(' expr optional_arg_list ')' ';'
    ;

optional_arg_list
    : /* empty */
    | ',' arg_list
    ;

return_stmt
    : RETURN expr_opt ';'
    ;

break_stmt
    : BREAK ';'
    ;

for_expr
    : var_declr        
    | assign_stmt      
    | expr             
    | /* empty */      
    ;


block_stmt
    : '{' statement_blocks '}'
    ;


condition
    : expr rel_op expr
    ;

rel_op
    : '>'
    | '<'
    | EQUALS
    | NOT_EQUALS
    ;

arg_list
    : expr
    | arg_list ',' expr
    | /* empty */
    ;

expr_opt
    : /* empty */
    | expr
    ;

expr
    : literal
    | expr PLUS expr
    | expr MINUS expr
    | expr MUL expr
    | expr DIV expr
    | '-' expr %prec UMINUS
    | ID
    | NEW CLASS_ID '(' ')'
    | expr '.' ID
    | expr '.' ID '(' arg_list ')'
    ;

method_call
    : ID '(' arg_list ')'
    ;

literal
    : NUM
    | CHAR_LIT
    | STR_LIT
    | BOOL_LIT
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

int main(int argc, char **argv) {
    yydebug = 1;  // Enable debugging
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open file: %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    return yyparse();
}
