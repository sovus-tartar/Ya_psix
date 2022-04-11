#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../headers/st.h"

int search_expr(struct lex_array_t arr)
{
    int i, br_state;
    
    br_state = 0;
    for (i = 0; i < arr.size; i++)
    {
        if (arr.lexem[i].kind == BRACE)
        {
            if (arr.lexem[i].lex.br == LBRAC)
                br_state += 1;
            else
            {
                br_state -=1;
            }
        }

        if (br_state < 0)
        {
            printf("ERROR\n");
            exit(0);
        }

        if (br_state == 0)
        {
            if (arr.lexem[i].kind == OP)
                if ((arr.lexem[i].lex.op == ADD) ||
                    (arr.lexem[i].lex.op == SUB))
                    return i;
        }

        
    }

    return -1;
}

int search_mult(struct lex_array_t arr)
{
    int i, count, br_state;
    count = -1;
    br_state = 0;

    for (i = 0; i < arr.size; i++)
    {
        if (arr.lexem[i].kind == BRACE)
        {
            if (arr.lexem[i].lex.br == LBRAC)
                br_state += 1;
            else
                br_state -=1;
        }

        if (br_state < 0)
        {
            printf("ERROR: wrong brace seq");
            abort();
        }
        if (br_state == 0)
        {
            if (arr.lexem[i].kind == OP)
                if ((arr.lexem[i].lex.op == MUL) ||
                    (arr.lexem[i].lex.op == DIV))
                    count = i;
        }
    }

    return count;
}

struct node_t *is_num(struct lex_array_t arr)
{
    struct node_t *node;

    
    node = calloc(1, sizeof(struct node_t));

    if (arr.lexem[0].kind == NUM)
    {
        node->state = NUMBER;
        node->node.number = arr.lexem[0].lex.num;
        return node;
    }
    else
    {
        printf("ERROR\n");
        exit(0);
    }
}
    

struct lex_array_t create_arr(struct lexem_t * first, int size) {
    struct lex_array_t temp;


    if (size <= 0) {
        printf("ERROR\n");
        exit(0);
    }

    temp.lexem = first;
    temp.size = size;

    return temp;
}

struct node_t *expr(struct lex_array_t arr)
{
    struct node_t *node;
    struct lex_array_t larr, rarr;
    int node_num;

    if (arr.size == 0) {
        printf("ERROR\n");
        exit(0);
    }

    if (arr.size == 1)
    {
        return is_num(arr);
    }

    if ((node_num = search_expr(arr)) == -1)
        return mult(arr);

    node = calloc(1, sizeof(struct node_t));

    

    larr = create_arr(arr.lexem, node_num);
    rarr = create_arr(arr.lexem + node_num + 1, arr.size - node_num - 1);

    node->state = EXPR;
    node->op = arr.lexem[node_num].lex.op;
    node->node.arr = arr;
    node->left = mult(larr);
    node->right = expr(rarr);

    return node;


}

struct node_t *mult(struct lex_array_t arr)
{
    struct node_t *node;
    struct lex_array_t larr, rarr;
    int node_num;

    if (arr.size == 0) {
        printf("ERROR\n");
        exit(0);
    }        
    
    if (arr.size == 1)
    {
        return is_num(arr);
    }

    if ((node_num = search_mult(arr)) == -1)
        return term(arr);

    node = calloc(1, sizeof(struct node_t));


    larr = create_arr(arr.lexem, node_num);
    rarr = create_arr(arr.lexem + node_num + 1, arr.size - node_num - 1);

    node->state = MULT;
    node->node.arr = arr;
    node->op = arr.lexem[node_num].lex.op;
    node->left = mult(larr);
    node->right = expr(rarr);

    return node;
}

struct node_t *term(struct lex_array_t arr)
{
    struct node_t *node;
    struct lex_array_t new_arr;

    if (arr.size == 0) {
        printf("ERROR\n");
        exit(0);
    }

    if (arr.size == 1)
    {
        return is_num(arr);
    }

    new_arr.lexem = arr.lexem + 1;
    new_arr.size = arr.size - 2;

    return expr(new_arr);

    
}

struct node_t *build_synt_tree(struct lex_array_t arr)
{

    struct node_t *tree_top;
    struct lex_array_t *temp;

    tree_top = expr(arr);

    return tree_top;
}

void del_tree(struct node_t * top) {

    if (top -> left)
        del_tree(top->left);
    
    if (top->left)
        del_tree(top->right);

    free(top);


}

int calc(struct node_t * top) {

    //printf("CALC\n");

    if (top->state == NUMBER)
        return top->node.number;

    switch(top->op) {
        case ADD:
            return calc(top->left) + calc(top->right);
            break;
        case SUB:
            return calc(top->left) - calc(top->right);
            break;
        case MUL:
            return calc(top->left) * calc(top->right);
            break;
        case DIV:
            return calc(top->left) / calc(top->right);
            break;
    }

    printf("Calculation error: wrong node\n");
    exit(0);

}

int main()
{
    struct lex_array_t arr;
    struct node_t *tree_top;
    
    arr = r_input();
    //print_lex_arr(arr);
    tree_top = build_synt_tree(arr);

    printf("%d\n", calc(tree_top));

    free(arr.lexem);
    del_tree(tree_top);

    return 0;
}