#include "../include/kvadr_head.h"

void unit_test(void){
    int i;

    struct equation_data debug[] =  {1, 4, -5, -5, 1,
                                     1, -4, -5, -1, 5,
                                     4, 5, 1, -1, -0.25,
                                     1, 2, 1, -1, NAN,
                                     1, -2, 1, 1, NAN,
                                     0, 5, -10, 2, NAN,
                                     0, 15, 30, -2, NAN,
                                     1, 4, 7, NAN, NAN,
                                     10, 8, 15, NAN, NAN,
                                     0, 0, 0, NAN, NAN};
    for(i = 0; i <= 10; i++){
        check_equation(debug[i].a, debug[i].b, debug[i].c, debug[i].x1_expect, debug[i].x2_expect);
    }
}

void check_equation(double a, double b, double c, double x1_expect, double x2_expect) {
    double x1 = NAN, x2 = NAN;

    equation_solver(a, b, c, &x1, &x2);

    if (((x1 = x1_expect) && (x2 = x2_expect)) || ((x1 = x2_expect) && (x2 = x1_expect))) {
        printf("a = %lf b = %lf c = %lf PASS\n", a, b, c);
    } else {
        printf("a = %lf b = %lf c = %lf FAILED\nx1 = %lf expected: x1 = %lf\nx2 = %lf expected: x2 = %lf", a, b, c, x1, x1_expect, x2, x2_expect);
    }
}