#include <stdio.h>
#include <stdlib.h>

int small_elem(int *arr, int N)
{
    int i, elem, num;
    i = 0;
    num = 0;
    elem = arr[0];
    for (i = 0; i < N; i++)
    {
        if (arr[i] < elem)
        {
            elem = arr[i];
            num = i;
        }
    }

    return num;
}

void sse_sort(int *arr, int N, int pos)
{
    int num, temp;
    num = 0;
    num = small_elem(arr + pos, N - pos) + pos;

    temp = arr[pos];
    arr[pos] = arr[num];
    arr[num] = temp;
}

int main()
{
    int N, i, pos;
    int *arr;
    scanf("%d", &N);

    arr = (int *)calloc(N, sizeof(int));

    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &pos);

    sse_sort(arr, N, pos);

    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);

    free(arr);
}
