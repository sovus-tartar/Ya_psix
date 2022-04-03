#pragma once

#include "../LX/lx.h"

enum node_state {
    EXPR,
    MULT,
    TERM,
    NUMBER
};



struct node_t {
    enum node_state state;
    enum operation_t op;
    union {
        struct lex_array_t arr;
        int number;
    } node;
    struct node_t *left;
    struct node_t *right;
};

int search_expr(struct lex_array_t arr);
int search_mult(struct lex_array_t arr);
struct node_t *is_num(struct lex_array_t arr);
struct lex_array_t create_arr(struct lexem_t * first, int size);
struct node_t *expr(struct lex_array_t arr);
struct node_t *mult(struct lex_array_t arr);
struct node_t *term(struct lex_array_t arr);
struct node_t *build_synt_tree(struct lex_array_t arr);
int calc(struct node_t * top);