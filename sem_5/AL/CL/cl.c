#include <stdio.h>
#include <stdlib.h>

struct list_t
{
    struct list_t *next;
    int data;
};

struct list_t *cl_push(struct list_t *pre, int val)
{

    struct list_t *temp;

    temp = pre->next;

    pre -> next = calloc(1, sizeof(struct list_t));
    assert(pre->next != 0);

    pre->next->next = temp;
    pre->next->data = val;

    return (pre->next);
}

struct list_t *cl_pop(struct list_t *pre)
{

    struct list_t *temp;

    pre->next->next = temp;

    free(pre->next);

    pre->next = temp;

    return temp;
}

int minimum(int const *arr, int num)
{
    int i, min;
    min = arr[0];
    for (i = 1; i < num; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

struct list_t *list_init(int n)
{
    int i;
    struct list_t *top, *curr;

    top = calloc(1, sizeof(struct list_t)); //1 time
    curr = top;

    for (i = 0; i < n - 1; i++)
    { //n - 1 times
        curr->next = calloc(1, sizeof(struct list_t));
        curr = curr->next;
    }
    curr->next = top;

    return top;
}

struct list_t *list_skip(struct list_t *node, int n)
{
    struct list_t *temp;
    int i;

    temp = node;

    for (i = 0; i < n; i++)
    {
        temp = temp->next;
    }

    return temp;
}

int coin_num(int *arr, int num, int sum)
{
    int number, i, j, k, p, min, pre;
    int *temp_arr;
    struct list_t *curr, *curr_top, *temp;

    curr_top = calloc(1, sizeof(struct list_t));
    j = 0;
    curr_top->next = curr_top;

    for (p = 1; p <= sum; p++)
    {
        if (p <= num)
        {
            if (arr[j] == p)
            {

                curr_top->next = cl_push(curr_top, 1);
                j++;
            }
            else
            {

                min = curr_top->data;
                pre = 0;

                for (i = 0; i < num; i++)
                {
                    pre = arr[i] - pre;
                    temp = list_skip(curr_top, pre);
                    if (temp->data < min)
                        min = temp->data;
                }

                curr_top->next = cl_push(curr_top, min);
            }
        }
        else
        {

            for (i = 0; i < num; i++)
            {
                pre = arr[i] - pre;
                temp = list_skip(curr_top, pre);
                if (temp->data < min)
                    min = temp->data;
            }

            temp = list_skip(curr_top, num);

            curr_top = cl_pop(temp);
        }
    }

    return curr_top -> next -> data;

}

void arr_sort(int *arr, int n)
{
    qsort(arr, n, sizeof(int), comp_int);
}

int comp_int(int val1, int val2)
{
    return (val1 - val2);
}

void delete_list(struct list_t *top)
{
    struct list_t *curr, *temp;
    curr = top;
    while (curr)
    {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
}

void display_list(struct list_t *top)
{
    struct list_t *curr;
    curr = top;
    while (curr)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

int main()
{
    int M, num, i;
    int *arr;

    scanf("%d%d", &M, &num);

    arr = calloc(num, sizeof(int));
    assert(arr != NULL);

    for (i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    arr_sort(arr, num);

    printf("%d", coin_num(arr, num, M));
}
