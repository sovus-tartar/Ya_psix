#include <stdio.h>
#include <stdlib.h>

struct node_t
{
    struct node_t *next;
    int data;
};

struct node_t *reverse(struct node_t *top)
{
    struct node_t *temp_ptr, *pre, *temp_next;
    if (top == NULL) 
        return top;
    
    temp_ptr = top->next;
    top->next = NULL;
    pre = top;
    //printf("%p\n", pre);
    while (temp_ptr != NULL)
    {
        temp_next = temp_ptr->next;
        temp_ptr->next = pre;
        pre = temp_ptr;
        temp_ptr = temp_next;
    }
    //printf("%p\n", pre);
    return pre;
}

int main()
{

    struct node_t *top, *curr;
    int i;

    top = calloc(1, sizeof(struct node_t));
    curr = top;
    curr->data = 0;
    for (i = 1; i < 11; i++)
    {
        curr->next = calloc(1, sizeof(struct node_t));
        curr = curr->next;
        curr->data = i;
    }

    curr = top;

    for (i = 0; curr != NULL; i++)
    {
        printf("%d %p\n", curr->data, curr);
        curr = curr->next;
    }
    printf("\n");

    top = reverse(top);
    curr = top;

    for (i = 0; curr != NULL; i++)
    {
        printf("%d %p\n", curr->data, curr);
        curr = curr->next;
    }
}