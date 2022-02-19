#include <stdio.h>
#include <stdlib.h>
struct Point
{
    int x;
    int y;
};
struct Rect
{
    struct Point lt; // left top
    struct Point rb; // right bottom
};

struct Rect * transform(const struct Rect * r)
{
    struct Point left_bottom, right_top;
    struct Rect * transp;
    int lengthx, widthy;

    transp = calloc(1, sizeof(struct Rect));

    right_top.x = r->lt.x;
    right_top.y = r->lt.y;

    lengthx = r->rb.x - r->lt.x;
    widthy = r->lt.y - r->rb.y;

    left_bottom.x = r->rb.x - lengthx - widthy;
    left_bottom.y = r->rb.y + (widthy - lengthx);

    transp->lt.x = left_bottom.x;
    transp->lt.y = right_top.y;
    transp->rb.x = right_top.x;
    transp->rb.y = left_bottom.y;

    return transp;
}

int main()
{
    struct Rect *rect, a = {{2, 4}, {7, 1}};
    rect = transform(&a);
    printf("%d %d %d %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y);
    printf("%d %d %d %d\n", rect->lt.x, rect->lt.y, rect->rb.x, rect->rb.y);
    free(rect);
    return 0;
}
