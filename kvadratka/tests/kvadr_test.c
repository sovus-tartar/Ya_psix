#include "../include/kvadr_head.h"

void unit_test(void){
    int i;

    struct equation_data debug[] =  {1, 4, -5, -5, 1, TWO_ROOTS, //0
                                     1, -4, -5, -1, 5, TWO_ROOTS, //1
                                     4, 5, 1, -1, -0.25, TWO_ROOTS,
                                     1, 2, 1, -1, NAN, ONE_ROOT,
                                     1, -2, 1, 1, NAN, ONE_ROOT,
                                     0, 5, -10, 2, NAN, ONE_ROOT,
                                     0, 15, 30, -2, NAN, ONE_ROOT,
                                     1, 4, 7, NAN, NAN, ZERO_ROOTS,
                                     10, 8, 15, NAN, NAN, ZERO_ROOTS,
                                     0, 0, 0, NAN, NAN, INF_ROOTS}; //9
    for(i = 0; i <= 9; i++){
        check_equation(debug[i].a, debug[i].b, debug[i].c, debug[i].x1_expect, debug[i].x2_expect, debug[i].num_expect);
    }
}

void check_equation(double a, double b, double c, double x1_expect, double x2_expect, int num_expect) {
    double x1 = NAN, x2 = NAN;
    int num;

    num = equation_solver(a, b, c, &x1, &x2);

    if ((((is_equal(x1, x1_expect)) && (is_equal(x2, x2_expect))) || ((is_equal(x1, x2_expect)) && (is_equal(x2, x1_expect)))) && (num == num_expect)) {
        printf("a = %lf b = %lf c = %lf PASS\n", a, b, c);
    } else {
        printf("a = %lf b = %lf c = %lf FAILED\nx1 = %lf expected: x1 = %lf\nx2 = %lf expected: x2 = %lf\nnum = %d expected: num = %d\n", a, b, c, x1, x1_expect, x2, x2_expect, num, num_expect);
    }
}