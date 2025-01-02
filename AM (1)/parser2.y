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

// Symbol table structures and functions
typedef struct symbol {
    char *name;
    int is_method;
    struct symbol *next;
} symbol_t;

typedef struct scope {
    symbol_t *symbols;
    struct scope *next;
} scope_t;

scope_t *current_scope = NULL;

void enter_scope() {
    scope_t *new_scope = (scope_t *)malloc(sizeof(scope_t));
    new_scope->symbols = NULL;
    new_scope->next = current_scope;
    current_scope = new_scope;
    printf("Entering new scope\n");
}

void exit_scope() {
    if (current_scope == NULL) return; // Safety check
    scope_t *old_scope = current_scope;
    current_scope = current_scope->next;

    symbol_t *symbols = old_scope->symbols;
    while (symbols) {
        symbol_t *next = symbols->next;
        free(symbols->name);
        free(symbols);
        symbols = next;
    }
    free(old_scope);
    printf("Exiting scope\n");
}

void add_symbol(char *name, int is_method) {
    if (current_scope == NULL) return; // Safety check
    symbol_t *new_symbol = (symbol_t *)malloc(sizeof(symbol_t));
    new_symbol->name = strdup(name);
    new_symbol->is_method = is_method;
    new_symbol->next = current_scope->symbols;
    current_scope->symbols = new_symbol;
    printf("Adding symbol: %s (method: %d)\n", name, is_method);
}

int check_symbol(char *name, int is_method) {
    if (current_scope == NULL) return 0; // Safety check
    scope_t *scope = current_scope;
    while (scope) {
        symbol_t *symbols = scope->symbols;
        while (symbols) {
            if (strcmp(symbols->name, name) == 0 && symbols->is_method == is_method) {
                return 1;
            }
            symbols = symbols->next;
        }
        scope = scope->next;
    }
    return 0;
}

void yyerror_with_expected(const char *s, const char *expected) {
    fprintf(stderr, "Error: %s at line %d, token: %s. Expected: %s\n", s, yylineno, yytext, expected);
    error_count++;
}

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
%right ASSIGN

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
    : type IDENTIFIER SEMICOLON {
        if (!check_symbol($2, 0)) {
            add_symbol($2, 0);
        } else {
            yyerror_with_expected("Variable already declared", ";");
            YYABORT;
        }
    }
    | modifier type IDENTIFIER SEMICOLON {
        if (!check_symbol($3, 0)) {
            add_symbol($3, 0);
        } else {
            yyerror_with_expected("Variable already declared", ";");
            YYABORT;
        }
    }
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
    : modifier type IDENTIFIER LPAREN parameter_list RPAREN LBRACE method_body RBRACE {
        if (!check_symbol($3, 1)) {
            add_symbol($3, 1);
        } else {
            yyerror_with_expected("Method already declared", ")");
            YYABORT;
        }
    }
    | type IDENTIFIER LPAREN parameter_list RPAREN LBRACE method_body RBRACE {
        if (!check_symbol($2, 1)) {
            add_symbol($2, 1);
        } else {
            yyerror_with_expected("Method already declared", ")");
            YYABORT;
        }
    }
    ;

parameter_list
    : parameter
    | parameter_list COMMA parameter
    | /* empty */
    ;

parameter
    : type IDENTIFIER {
        if (!check_symbol($2, 0)) {
            add_symbol($2, 0);
        } else {
            yyerror_with_expected("Parameter already declared", ",");
            YYABORT;
        }
    }
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
    : IDENTIFIER ASSIGN expression {
        if (!check_symbol($1, 0)) {
            yyerror_with_expected("Variable not declared", "=");
            YYABORT;
        }
    }
    ;

loop_statement
    : DO LBRACE statement_list RBRACE WHILE LPAREN condition RPAREN SEMICOLON
    | FOR LPAREN for_init SEMICOLON condition_opt SEMICOLON for_increment RPAREN LBRACE statement_list RBRACE
    ;

for_init
    : variable_declaration
    | assignment_statement
    | /* empty */
    ;

for_increment
    : assignment_statement
    | expression
    | /* empty */
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
    : LBRACE {
        enter_scope();
    } statement_list RBRACE {
        exit_scope();
    }
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
    | IDENTIFIER {
        if (!check_symbol($1, 0)) {
            yyerror_with_expected("Variable not declared", $1);
            YYABORT;
        }
    }
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
    : IDENTIFIER LPAREN argument_list RPAREN {
        if (!check_symbol($1, 1)) {
            yyerror_with_expected("Method not declared", $1);
            YYABORT;
        }
    }
    | IDENTIFIER DOT IDENTIFIER LPAREN argument_list RPAREN {
        if (!check_symbol($1, 0)) {
            yyerror_with_expected("Variable not declared", $1);
            YYABORT;
        }
        if (!check_symbol($3, 1)) {
            yyerror_with_expected("Method not declared", $3);
            YYABORT;
        }
    }
    ;

object_creation
    : NEW IDENTIFIER LPAREN RPAREN {
        if (!check_symbol($2, 0)) {
            yyerror_with_expected("Class not declared", $2);
            YYABORT;
        }
    }
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
    // Initialize the global scope
    enter_scope();

    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }

    int result = yyparse();

    // Exit the global scope
    exit_scope();

    if (error_count > 0) {
        fprintf(stderr, "Parsing failed with %d errors.\n", error_count);
    } else {
        fprintf(stdout, "Parsing succeeded with no errors.\n");
    }

    return result;
}
