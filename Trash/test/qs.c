#include <stdio.h>
#include <stdlib.h>

struct long_num
{
    int n;
    int *arr;
};

int comp(struct long_num *val1, struct long_num *val2)
{
    int n1, n2, i, n, comp;
    int *arr1, *arr2;

    n1 = val1->n;
    n2 = val2->n;

    arr1 = val1->arr;
    arr2 = val2->arr;

    if (n1 > n2)
        n = n1;
    else
        n = n2;

    for (i = 0; i < n; i++)
    {
        int temp1, temp2;

        if ((n1 + i) >= n)
            temp1 = arr1[i];
        else
            temp1 = 0;

        if ((n2 + i) >= n)
            temp2 = arr2[i];
        else
            temp2 = 0;

        if (temp1 > temp2)
        {
            return 1;
        }

        if (temp1 < temp2)
        {
            return -1;
        }
    }

    return 0;
}

int main()
{
    int num, i;
    struct long_num *ptr;

    scanf("%d", &num);

    ptr = (struct long_num *)calloc(num, sizeof(struct long_num));

    for (i = 0; i < num; i++)
    {
        int n, k;
        scanf("%d", &n);
        ptr[i].arr = calloc(n, sizeof(int));
        ptr[i].n = n;
        for (k = 0; k < n; k++)
            scanf("%d", &(ptr[i].arr[k]));
    }
    qsort(ptr, num, sizeof(struct long_num), (int (*)(const void *, const void *))comp);

    for (i = 0; i < num; i++)
    {
        int n, k;
        n = ptr[i].n;
        printf("%d ", n);
        for (k = 0; k < n; k++)
        {
            printf("%d ", ptr[i].arr[k]);
        }
        printf("\n");
    }

    for (i = 0; i < num; i++)
    {
        free(ptr[i].arr);
    }

    free(ptr);
    return 0;
}