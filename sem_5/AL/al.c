#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct node_t
{
    struct node_t *next;
    int data;
};

int is_even(int num)
{
    return !(num % 2);
}

struct node_t *fill_new_node(struct node_t *old, int cont)
{
    struct node_t *new;

    new = calloc(1, sizeof(struct node_t));
    assert(new > 0);

    old->next = new;

    new->data = cont;

    return (new);
}

void connect_lists(struct node_t *bottom, struct node_t *top)
{
    bottom->next = top;
}

struct node_t *read_list(FILE *inp)
{
    int temp, even, odd;
    struct node_t *top, *curr_odd, *curr_even, *top_odd;

    even = 0;
    odd = 0;

    top = calloc(1, sizeof(struct node_t));
    assert(top > 0);
    curr_even = top;

    curr_odd = calloc(1, sizeof(struct node_t));
    assert(curr_odd > 0);
    top_odd = curr_odd;

    while (fscanf(inp, "%d", &temp) != EOF)
    {

        //printf("%d BLA\n", temp);
        if (is_even(temp))
        {
            if (even)
                curr_even = fill_new_node(curr_even, temp);
            else
                curr_even->data = temp;
            even += 1;
        }
        else
        {
            if (odd)
                curr_odd = fill_new_node(curr_odd, temp);
            else
                curr_odd->data = temp;
            odd += 1;
        }
    }

    if (odd == 0)
        return top;
    if (even == 0) 
        return top_odd;

    connect_lists(curr_even, top_odd);

    return top;
}

void display_list(struct node_t *top)
{
    struct node_t *curr;
    curr = top;
    while (curr)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

int main()
{
    FILE *fptr;
    struct node_t *lptr;

    fptr = fopen("111.in", "r");
    if (fptr == NULL)
        perror("Error opening file: ");
    assert(fptr > 0);

    lptr = read_list(fptr);
    assert(lptr > 0);

    display_list(lptr);
    fclose(fptr);
}

void delete_list(struct node_t *top)
{
    struct node_t *curr, *temp;
    curr = top;
    while (curr)
    {   
        temp = curr -> next;

        free(curr);

        curr = temp;
    }
}