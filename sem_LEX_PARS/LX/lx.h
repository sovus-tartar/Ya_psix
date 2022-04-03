#pragma once


enum lexem_kind_t
{
    OP,
    BRACE,
    NUM,
    SPACE
};

enum operation_t
{
    ADD,
    SUB,
    MUL,
    DIV
};

enum braces_t
{
    LBRAC,
    RBRAC
};

struct lexem_t
{
    enum lexem_kind_t kind;
    union
    {
        enum braces_t br;
        enum operation_t op;
        int num;
    } lex;
};

struct lex_array_t
{
    struct lexem_t *lexem;
    int size;
};

struct lex_list
{
    struct lexem_t elem;
    struct lex_list *next;
};

struct char_list
{
    char c;
    struct char_list *next;
};

struct lex_list add_elem(char c);
struct lex_array_t list_to_arr(struct lex_list *top, int count);
void del_lex_list(struct lex_list *top);
struct lex_array_t r_input();
void print_lex_arr(struct lex_array_t A);
