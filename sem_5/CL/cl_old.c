#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct list_t
{
    struct list_t *next;
    int data;
};

struct list_t *cl_push(struct list_t *pre, int val)
{

    struct list_t *temp;

    temp = pre->next;

    pre->next = calloc(1, sizeof(struct list_t));
    assert(pre->next != 0);

    pre->next->next = temp;
    pre->next->data = val;

    return (pre->next);
}

struct list_t *cl_pop(struct list_t *pre)
{

    struct list_t *temp;

    temp = pre->next->next;

    free(pre->next);

    pre->next = temp;

    return pre;
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
    int number, i, j, k, p, min, pre, l;
    int *temp_arr;
    struct list_t *curr, *curr_top, *temp;

    curr_top = calloc(1, sizeof(struct list_t));
    j = 0;
    curr_top->next = curr_top;
    //display_list(curr_top, 1);

    for (p = 1; p <= sum; p++)
    {
        if (p <= arr[num - 1])
        {
            if (arr[j] == p)
            {

                curr_top->next = cl_push(curr_top, 1);
                j++;
            }
            else
            {
                temp = curr_top -> next;
                min = sum;
                pre = 0;
                l = 0;
                for (i = 0; arr[i] < p; i++)
                {
                    if (i == 0)
                        pre = arr[0];
                    else 
                        pre = arr[i] - arr[i - 1];
                    temp = list_skip(temp, pre);
                    //printf("current: %d\n",temp -> data);
                    if ((temp->data < min) && (temp->data != 0))
                    {
                        min = temp->data;
                        l = 1;
                    }
                }
                if ((i == 0) || (l == 0))
                    min = -1;
                curr_top->next = cl_push(curr_top, min + 1);
            }
        }
        else
        {

            min = sum;
            pre = 0;
            l = 0;
            for (i = 0; i < num; i++)
            {
                if (i == 0)
                        pre = arr[0];
                    else 
                        pre = arr[i] - arr[i - 1];
                temp = list_skip(temp, pre);
                if ((temp->data < min) && (temp->data != 0))
                {
                    min = temp->data;
                    l = 1;
                }
            }
            if ((i == 0) || (l == 0))
                min = -1;

            temp = list_skip(curr_top, arr[num-1]);
            curr_top = cl_pop(temp);

            curr_top->next = cl_push(curr_top, min + 1);

            
        }

        //display_list(curr_top, arr[num - 1]);
    }
    //display_list(curr_top, p);
    return curr_top->next->data;
}

int comp_int(int *val1, int *val2)
{
    return (*val1 - *val2);
}

void arr_sort(int *arr, int n)
{
    qsort(arr, n, sizeof(int), (int *)comp_int);
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

void display_list(struct list_t *top, int n)
{
    struct list_t *curr;
    int i;
    curr = top->next;
    printf("LIST:\n");
    for (i = 0; i < n; i++)
    {
        printf("i = %d: %d on %p\n", n - i - 1, curr->data, curr);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    int M, num, i;
    int *arr;

    scanf("%d%d", &M, &num);

    arr = calloc(num, sizeof(int));
    assert(arr != NULL);

    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, num, sizeof(int), (int *)comp_int);

    /*
    for (i = 0; i < num; i++)
        printf("%d ", arr[i]);
        
    

    printf("\n"); */

    printf("%d\n", coin_num(arr, num, M));
}