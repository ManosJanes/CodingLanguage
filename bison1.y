%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
extern int yylineno;
extern char *yytext;
extern int yylex();
void yyerror(const char *s);

int error_count = 0;

typedef struct Error {
    int line;
    char *message;
    struct Error *next;
} Error;

Error *error_l = NULL;

void add_error(int line, const char *message) {
    Error *n_error = (Error *)malloc(sizeof(Error));
    n_error->line = line;
    n_error->message = strdup(message);
    n_error->next = error_l;
    error_l = n_error;
}

void write_errors_to_file() {
    FILE *file = fopen("errors.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Δεν μπόρεσα να ανοίξω το errors.txt.\n");
        return;
    }
    Error *current = error_l;
    while (current != NULL) {
        fprintf(file, "Σφάλμα: %s στη γραμμή %d\n", current->message, current->line);
        current = current->next;
    }
    fclose(file);
}

// Function to clear the error list
void clear_errors() {
    Error *current = error_l;
    while (current != NULL) {
        Error *next = current->next;
        free(current->message);
        free(current);
        current = next;
    }
    error_l = NULL;
}
%}

%union {
    char *str;
    double num;
}

%token <str> CHAR_LIT
%token <str> STR_LIT
%token <num> NUM
%token <str> UPPER_ID
%token <str> ID

%token INT
%token CHAR
%token DBL
%token BOOL
%token STR
%token PUB
%token PRIV
%token CLS
%token NEW
%token RETURN
%token VOID
%token IF
%token ELSE
%token WHILE
%token DO
%token FOR
%token SWITCH
%token CASE
%token DEFAULT
%token BREAK
%token BOOL_LIT
%token PRINT

%token AR_PAREN
%token DE_PAREN
%token AR_AG
%token DE_AG
%token ERWT
%token KOM
%token ISON
%token SIN
%token MEION
%token SINEP
%token INEK
%token MIK
%token MEG
%token MIKIS
%token MEGIS
%token AND
%token OR
%token EPI
%token DIA
%token TEL
%token ANKAT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left OR
%left AND
%left SINEP INEK
%left MIK MEG
%left SIN MEION
%left EPI DIA
%right ISON

%start prog

%%

prog
    : class_decl_list
    ;

class_decl_list
    : class_decl
    | class_decl_list class_decl
    ;

class_decl
    : PUB CLS UPPER_ID AR_AG class_body DE_AG
    | CLS UPPER_ID AR_AG class_body DE_AG
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
    : data_type var_declrs ERWT
    | access_mod data_type var_declrs ERWT
    ;

var_declrs
    : var_declr 
    | var_declrs KOM var_declr
    ;

var_declr
    : ID
    | ID ISON expr
    ;

access_mod
    : PUB
    | PRIV
    ;

method_decl_list
    : method_decl
    | method_decl_list method_decl
    | /* empty */
    ;

method_decl
    : access_mod data_type ID AR_PAREN param_list DE_PAREN AR_AG method DE_AG
    | data_type ID AR_PAREN param_list DE_PAREN AR_AG method DE_AG
    ;

param_list
    : param
    | param_list KOM param
    | /* empty */
    ;

param
    : data_type ID
    ;

method
    : stmt_list
    ;

stmt_list
    : stmt
    | stmt_list stmt
    | /* empty */
    ;

stmt
    : assign_stmt
    | loop_stmt
    | control_stmt
    | break_stmt
    | print_stmt
    | switch_stmt
    | return_stmt
    | block_stmt
    | var_decl
    | error { add_error(yylineno, "syntax error"); yyerrok; }
    ;

assign_stmt
    : ID ISON expr
    ;

loop_stmt
    : DO AR_AG stmt_list DE_AG WHILE AR_PAREN condition DE_PAREN ERWT
    | FOR AR_PAREN for_1 ERWT condition_1 ERWT for_2 DE_PAREN AR_AG stmt_list DE_AG
    ;

for_1
    : var_decl
    | assign_stmt
    | expr
    | /* empty */
    ;

for_2
    : assign_stmt
    | expr
    | /* empty */
    ;

control_stmt
    : IF AR_PAREN condition DE_PAREN AR_AG stmt_list DE_AG %prec LOWER_THAN_ELSE
    | IF AR_PAREN condition DE_PAREN AR_AG stmt_list DE_AG ELSE AR_AG stmt_list DE_AG
    ;

switch_stmt
    : SWITCH AR_PAREN expr DE_PAREN AR_AG case_clauses default_clause_opt DE_AG
    ;

case_clauses
    : /* empty */
    | case_clauses case_clause
    ;

case_clause
    : CASE expr ANKAT stmt_list
    ;

default_clause_opt
    : /* empty */
    | DEFAULT ANKAT stmt_list
    ;

print_stmt
    : PRINT AR_PAREN STR_LIT print_arg_list DE_PAREN ERWT
    ;

print_arg_list
    : /* empty */
    | KOM expr
    | print_arg_list KOM expr
    ;

return_stmt
    : RETURN expr_opt ERWT
    ;

break_stmt
    : BREAK ERWT
    ;

block_stmt
    : AR_AG stmt_list DE_AG
    ;

expr_opt
    : /* empty */
    | expr
    ;

condition
    : expr rel_op expr
    | expr
    ;

condition_1
    : /* empty */
    | condition
    ;

binary_expr
    : expr binary_op expr
    ;

unary_expr
    : unary_op expr
    ;

expr
    : literal
    | ID
    | binary_expr
    | unary_expr
    | method_call
    | obj_create
    ;

rel_op
    : MIK
    | MEG
    | SINEP
    | INEK
    | MIKIS
    | MEGIS
    ;

method_call
    : ID TEL ID AR_PAREN arg_list DE_PAREN
    ;

obj_create
    : NEW ID AR_PAREN DE_PAREN
    ;

arg_list
    : /* empty */
    | expr
    | arg_list KOM expr
    ;

literal
    : NUM
    | CHAR_LIT
    | STR_LIT
    | BOOL_LIT
    ;

binary_op
    : SIN
    | MEION
    | EPI
    | DIA
    | AND
    | OR
    ;

unary_op
    : MEION
    | "!"
    ;

data_type
    : INT
    | CHAR
    | DBL
    | BOOL
    | STR
    | VOID
    | ID
    ;

%%

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
