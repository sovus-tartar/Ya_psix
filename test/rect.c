#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int h;   // часы
    int min; // минуты (от 0 до 59)
} TicTac;

TicTac after(TicTac a, int min)
{

    TicTac c;

    c.min = (a.min + min) % 60;
    c.h = (a.h - 1 + ((a.min + min) / 60)) % 12 + 1;

    printf("%d\n%d\n", c.h, c.min);
    return c;
}

int main()
{
    TicTac a, c;
    int min;

    scanf("%d %d", &(a.h), &(a.min));
    scanf("%d", &min);
    c = after(a, min);
    printf("%.2d:%.2d\n", c.h, c.min);
    return 0;
}