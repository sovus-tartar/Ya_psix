#include <stdio.h>

int moveright(int *arr, int key, int last)
{
    int i, pos, temp, temp1;
    if (last == 0)
        return last;

    for (i = 1; i < last; i++)
        if (arr[i] > key)
            break;

    pos = i;
    //printf("pos = %d last = %d i = %d\n", pos, last, i);

    temp = arr[i];
    for (i = pos; i <= last; i++)
    {
        int k;
        temp1 = arr[i];
        arr[i] = temp;
        temp = temp1;

        // for (k = 0; k < 6; k++)
        //   printf("%d ", arr[k]);
        //printf("\n");
    }
    return pos;
}

void inssort(int *arr, int len)
{
    int i;
    for (i = 0; i < len; ++i)
    {
        int key, pos, k;
        key = arr[i];
        printf("key = %d i = %d\n", key, i);
        pos = moveright(arr, key, i);
        arr[pos] = key;
        for (k = 0; k < 6; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }
}

int main()
{
    int i;
    int arr[6] = {1, 2, 4, 5, 3, 2};

    printf("%d\n", moveright(arr, 3, 4));

    for (i = 0; i < 6; i++)
        printf("%d ", arr[i]);
}