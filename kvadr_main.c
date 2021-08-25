#include "kvadr_head.h"
int main(void) {
    printf("Square equations solver\n");
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 =NAN;
    int num;

    enter(&a, &b, &c);

    num = square_solver(a, b, c, &x1, &x2);

    result(num, x1, x2);

    return 0;
}
