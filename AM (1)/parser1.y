%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
extern int yylineno;
extern char *yytext;
extern int yylex();
void yyerror(const char *s);

// Error counter
int error_count = 0;

%}

%union {
    char *str;
    double num;
}

%token <str> IDENTIFIER
%token <str> CAPITALIZED_IDENTIFIER
%token <str> STRING_LITERAL
%token <str> CHAR_LITERAL
%token <num> NUMBER

%token PUBLIC
%token PRIVATE
%token CLASS
%token INT
%token CHAR
%token DOUBLE
%token BOOLEAN
%token STRING
%token VOID
%token NEW
%token RETURN
%token IF
%token ELSE
%token WHILE
%token DO
%token FOR
%token SWITCH
%token CASE
%token DEFAULT
%token BREAK
%token BOOLEAN_LITERAL
%token OUT_PRINT
%token THEN

%token LPAREN
%token RPAREN
%token LBRACE
%token RBRACE
%token SEMICOLON
%token COMMA
%token ASSIGN
%token EQ
%token NEQ
%token LT
%token GT
%token LE
%token GE
%token AND
%token OR
%token PLUS
%token MINUS
%token MUL
%token DIV
%token DOT
%token COLON

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left OR
%left AND
%left EQ NEQ
%left LT GT LE GE
%left PLUS MINUS
%left MUL DIV
%right ASSIGNvimeo

%start program

%%

program
    : class_declaration_list
    ;

class_declaration_list
    : class_declaration
    | class_declaration_list class_declaration
    ;

class_declaration
    : PUBLIC CLASS CAPITALIZED_IDENTIFIER LBRACE class_body RBRACE
    | CLASS CAPITALIZED_IDENTIFIER LBRACE class_body RBRACE
    ;

class_body
    : variable_declaration_list method_declaration_list
    ;

variable_declaration_list
    : variable_declaration
    | variable_declaration_list variable_declaration
    | /* empty */
    ;

variable_declaration
    : type variable_declarators SEMICOLON
    | modifier type variable_declarators SEMICOLON
    ;

variable_declarators
    : variable_declarators COMMA variable_declarator
    | variable_declarator 
    ;

variable_declarator
    : IDENTIFIER
    | IDENTIFIER ASSIGN expression
    ;


modifier
    : PUBLIC
    | PRIVATE
    ;

method_declaration_list
    : method_declaration
    | method_declaration_list method_declaration
    | /* empty */
    ;

method_declaration
    : modifier type IDENTIFIER LPAREN parameter_list RPAREN LBRACE method_body RBRACE
    | type IDENTIFIER LPAREN parameter_list RPAREN LBRACE method_body RBRACE
    ;

parameter_list
    : parameter
    | parameter_list COMMA parameter
    | /* empty */
    ;

parameter
    : type IDENTIFIER
    ;

method_body
    : statement_list
    ;

statement_list
    : statement
    | statement_list statement
    | /* empty */
    ;

statement
    : assignment_statement
    | loop_statement
    | control_statement
    | print_statement
    | return_statement
    | break_statement
    | block_statement
    | switch_statement
    | variable_declaration
    ;

assignment_statement
    : IDENTIFIER ASSIGN expression 
    ;

loop_statement
    : DO LBRACE statement_list RBRACE WHILE LPAREN condition RPAREN SEMICOLON
    | FOR LPAREN for_init condition_opt SEMICOLON for_increment RPAREN LBRACE statement_list RBRACE
    ;

for_init
    : variable_declaration
    | assignment_statement
    | expression
    | /* empty */
    ;

for_increment
    : assignment_statement
    | expression
    ;

control_statement
    : IF LPAREN condition RPAREN LBRACE statement_list RBRACE %prec LOWER_THAN_ELSE
    | IF LPAREN condition RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE
    ;

switch_statement
    : SWITCH LPAREN expression RPAREN LBRACE case_clauses default_clause_opt RBRACE
    ;

case_clauses
    : /* empty */
    | case_clauses case_clause
    ;

case_clause
    : CASE expression COLON statement_list
    ;

default_clause_opt
    : /* empty */
    | DEFAULT COLON statement_list
    ;

print_statement
    : OUT_PRINT LPAREN STRING_LITERAL print_argument_list RPAREN SEMICOLON
    ;

print_argument_list
    : /* empty */
    | COMMA expression
    | print_argument_list COMMA expression
    ;

return_statement
    : RETURN expression_opt SEMICOLON
    ;

break_statement
    : BREAK SEMICOLON
    ;

block_statement
    : LBRACE statement_list RBRACE
    ;

expression_opt
    : /* empty */
    | expression
    ;

condition_opt
    : /* empty */
    | condition
    ;

condition
    : expression relational_operator expression
    | expression
    ;

relational_operator
    : LT
    | GT
    | EQ
    | NEQ
    | LE
    | GE
    ;

expression
    : literal
    | IDENTIFIER
    | binary_expression
    | unary_expression
    | method_call
    | object_creation
    ;

binary_expression
    : expression binary_operator expression
    ;

unary_expression
    : unary_operator expression
    ;

method_call
    : IDENTIFIER DOT IDENTIFIER LPAREN argument_list RPAREN
    ;

object_creation
    : NEW IDENTIFIER LPAREN RPAREN
    ;

argument_list
    : /* empty */
    | expression
    | argument_list COMMA expression
    ;

literal
    : NUMBER
    | CHAR_LITERAL
    | STRING_LITERAL
    | BOOLEAN_LITERAL
    ;

binary_operator
    : PLUS
    | MINUS
    | MUL
    | DIV
    | AND
    | OR
    ;

unary_operator
    : MINUS
    | "!"
    ;

type
    : INT
    | CHAR
    | DOUBLE
    | BOOLEAN
    | STRING
    | VOID
    | IDENTIFIER
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d, token: %s\n", s, yylineno, yytext);
    error_count++;
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
    if (error_count > 0) {
        fprintf(stderr, "Parsing failed with %d errors.\n", error_count);
    } else {
        fprintf(stdout, "Parsing succeeded with no errors.\n");
    }
    return result;
}
