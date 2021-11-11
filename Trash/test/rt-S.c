#include <stdio.h>

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

struct Rect transform(struct Rect r)
{
    struct Point left_bottom, right_top;
    struct Rect transp;

    left_bottom.x = r.lt.x;
    left_bottom.y = r.rb.y;

    right_top.x = r.rb.x + ((r.lt.y - r.rb.y) - (r.rb.x - r.lt.x));
    right_top.y = r.lt.y - ((r.lt.y - r.rb.y) + (r.rb.x - r.lt.x));

    transp.lt = left_bottom;
    transp.rb = right_top;

    return transp;
}

int main()
{
    struct Rect rect, a = {{-6, 3}, {-2, 1}};
    rect = transform(a);
    printf("%d %d %d %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y);
    printf("%d %d %d %d\n", rect.lt.x, rect.lt.y, rect.rb.x, rect.rb.y);
    return 0;
}
