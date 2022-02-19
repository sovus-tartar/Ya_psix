#include <stdio.h>
#include <stdlib.h>

struct time
{
    int hh;
    int mm;
    int min;
};

void time_shift(int N, struct time *arr)
{
    int i;
    for (i = 0; i < N; i++)
    {
        int delta;

        delta = (arr[i].mm + arr[i].min) / 60;

        arr[i].hh = (arr[i].hh + delta) % 24;
        arr[i].mm = (arr[i].mm + arr[i].min) % 60;
    }
}

int comp(const void *t1, const void *t2)
{
    struct time *time1, *time2;

    time1 = (struct time *)t1;
    time2 = (struct time *)t2;

    if (time1->hh > time2->hh)
        return 1;
    if (time2->hh > time1->hh)
        return -1;
    if (time1->mm > time2->mm)
        return 1;
    if (time2->mm > time1->mm)
        return -1;
    return 0;
}

void time_sort(int N, struct time *arr)
{
    qsort(arr, N, sizeof(struct time), comp);
}

int main()
{
    struct time *arr;
    int N, i;

    scanf("%d", &N);

    arr = calloc(N, sizeof(struct time));

    for (i = 0; i < N; i++)
    {
        scanf("%d:%d %d", &arr[i].hh, &arr[i].mm, &arr[i].min);
    }

    time_shift(N, arr);
    time_sort(N, arr);
    for (i = 0; i < N; i++)
    {
        printf("%.2d:%.2d\n", arr[i].hh, arr[i].mm);
    }

    free(arr);
}