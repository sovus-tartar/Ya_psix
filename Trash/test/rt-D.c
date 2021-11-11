#include <stdio.h>

struct Point
{
    float x;
    float y;
};

int in_region(struct Point p)
{
    //x*x + 1
    //-x*x-2
    if ((p.y - (p.x * p.x) - 1 >= 0) || (p.y + (p.x * p.x) + 2 <= 0))
        return 1;
    else
        return 0;
}

int main()
{
    struct Point p = {0, 0};

    scanf("%f %f", &p.x, &p.y);

    printf("%d", in_region(p));
}