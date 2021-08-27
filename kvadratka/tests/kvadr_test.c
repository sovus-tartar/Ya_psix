#include "../include/kvadr_head.h"

void unit_test(void){
    int element_number;

    printf("Debug mode started!\n");

    struct equation_data ref_equations[] =  {1, 4, -5, -5, 1, TWO_ROOTS, //0
                                     1, -4, -5, -1, 5, TWO_ROOTS, //1
                                     4, 5, 1, -1, -0.25, TWO_ROOTS,
                                     1, 2, 1, -1, NAN, ONE_ROOT,
                                     1, -2, 1, 1, NAN, ONE_ROOT,
                                     0, 5, -10, 2, NAN, ONE_ROOT,
                                     0, 15, 30, -2, NAN, ONE_ROOT,
                                     1, 4, 7, NAN, NAN, ZERO_ROOTS,
                                     10, 8, 15, NAN, NAN, ZERO_ROOTS,
                                     0, 0, 0, NAN, NAN, INF_ROOTS}; //9

    for (element_number = 0; element_number <= 9; element_number++){
        check_equation(ref_equations[element_number].a, ref_equations[element_number].b,
                       ref_equations[element_number].c, ref_equations[element_number].x1_expect,
                       ref_equations[element_number].x2_expect, ref_equations[element_number].num_expect);
    }
}

void check_equation(double a, double b, double c, double x1_expect, double x2_expect, int num_expect) {
    double x1 = NAN, x2 = NAN;
    int num = equation_solver(a, b, c, &x1, &x2);

    if (((is_equal(x1, x1_expect) && is_equal(x2, x2_expect))  ||
         (is_equal(x1, x2_expect) && is_equal(x2, x1_expect))) &&
         (num == num_expect)) {
        printf("a = %lf b = %lf c = %lf PASS\n", a, b, c);
    } else {
        printf("a = %lf b = %lf c = %lf FAILED\n"
               "x1 = %lf expected: x1 = %lf\n"
               "x2 = %lf expected: x2 = %lf\n"
               "num = %d expected: num = %d\n", a, b, c, x1, x1_expect, x2, x2_expect, num, num_expect);
    }
}