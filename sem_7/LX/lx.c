#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

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
    int capacity;
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

struct lex_list add_elem(char c)
{

    struct lex_list temp;

    if (isdigit(c))
    {
        ungetc(c, stdin);
        scanf("%d", &temp.elem.lex.num);
        temp.elem.kind = NUM;
    }
    else
    {
        switch (c)
        {
        case '+':
            temp.elem.kind = OP;
            temp.elem.lex.op = ADD;
            break;
        case '-':
            temp.elem.kind = OP;
            temp.elem.lex.op = SUB;
            break;
        case '*':
            temp.elem.kind = OP;
            temp.elem.lex.op = MUL;
            break;
        case '/':
            temp.elem.kind = OP;
            temp.elem.lex.op = DIV;
            break;
        case '(':
            temp.elem.kind = BRACE;
            temp.elem.lex.br = LBRAC;
            break;
        case ')':
            temp.elem.kind = BRACE;
            temp.elem.lex.br = RBRAC;
            break;
        case ' ':
            break;
        case '\t':
            break;
        case '\n':
            break;
        case '\r':
            break;
        default:
            printf("ERROR\n");
            exit(0);
        }
    }

    return temp;
}

struct lex_array_t list_to_arr(struct lex_list *top, int count)
{
    int i;
    struct lex_array_t temp;

    temp.lexem = calloc(count, sizeof(struct lexem_t));

    for (i = 0; i < count; i++)
    {
        assert(top);
        temp.lexem[i] = top->elem;
        top = top->next;
    }

    temp.size = count;
    temp.capacity = count * sizeof(struct lexem_t);

    return temp;
}

void del_lex_list(struct lex_list *top)
{

    while (top)
    {
        struct lex_list *temp;
        temp = top->next;
        free(top);
        top = temp;
    }
}

struct lex_array_t r_input()
{
    struct lex_array_t arr;
    struct lex_list *top, *curr;
    char c;
    int count;

    count = 0;

    top = calloc(1, sizeof(struct lex_list));
    assert(top);
    curr = top;

    while ((c = getchar()) != '\n')
    {
        if ((c != ' ') && (c != '\t') && (c != '\r'))
        {
            *curr = add_elem(c);
            curr->next = calloc(1, sizeof(struct lex_list));
            curr = curr->next;
            assert(curr);
            count += 1;
        }
    }

    arr = list_to_arr(top, count);

    del_lex_list(top);

    return arr;
}

void print_lex_arr(struct lex_array_t A)
{
    int i;

    for (i = 0; i < A.size; i++)
    {
        switch (A.lexem[i].kind)
        {
        case OP:
            switch (A.lexem[i].lex.op)
            {
            case ADD:
                printf("PLUS ");
                break;
            case SUB:
                printf("MINUS ");
                break;
            case MUL:
                printf("MUL ");
                break;
            case DIV:
                printf("DIV ");
                break;
            }
            break;
        case BRACE:
            switch (A.lexem[i].lex.br)
            {
            case LBRAC:
                printf("LBRAC ");
                break;
            case RBRAC:
                printf("RBRAC ");
                break;
            }
            break;
        case NUM:
            printf("NUMBER:%d ", A.lexem[i].lex.num);
            break;
        default:
            printf("ERROR: UKNOWN LEXEM TYPE\n");
            abort();
        }
    }
}

int main()
{

    struct lex_array_t A;

    A = r_input();

    print_lex_arr(A);
    printf("\n");
}