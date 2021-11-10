#include <stdio.h>
#include <stdlib.h>

int papers(int n, int *arr)
{
    int i;

    for (i = n - 1; i > 0; i--)
    {
        arr[i - 1] += arr[i] / 2;
    }
    return arr[0];
}

int main()
{
    int n, i;
    int *arr;

    scanf("%d", &n);

    arr = calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", papers(n, arr));

    free(arr);
}