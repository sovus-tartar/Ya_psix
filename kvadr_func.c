#include "kvadr_head.h"

void enter(double* a, double* b, double* c){

    int i = 0;
    while (i != 3) {
        i = 0;
        printf("ax^2 + bx + c = 0\nEnter a:");
        i = i + scanf("%lf", a);
        printf("Enter b:");
        i = i + scanf("%lf", b);
        printf("Enter c:");
        i = i + scanf("%lf", c);
        if (i != 3) {
            printf("Wrong input. Try again\n");
            getchar();
        }
    }
}

int square_solver(double a, double b, double c, double* x1, double* x2){

    double dis = NAN, sqrt_dis = NAN;

    if ((is_equal(a, 0)) && (is_equal(b, 0)) && (is_equal(c, 0))){
        return INF_ROOTS;

    } else if ((is_equal(a, 0)) && (is_equal(b, 0))){
        return ZERO_ROOTS;
    } else if (is_equal(a, 0)) {
        assert (x1 != NULL);
        *x1 = -c / b;

        return ONE_ROOT;
    } else {

        dis = b * b - 4 * a * c;

        if (dis > 0) {
            sqrt_dis = sqrt(dis);
            assert (x1 != NULL);
            assert (x2 != NULL);
            *x1 = (-b + sqrt_dis) / (2 * a);
            *x2 = (-b - sqrt_dis) / (2 * a);

            return TWO_ROOTS;

        } else if (dis < 0) {
            return ZERO_ROOTS;

        } else {
            assert (x1 != NULL);
            *x1 = solve_linear(b, c);

            return ONE_ROOT;

        }
    }
}

char is_equal(double a, double b) {
    if (abs(a - b) < accuracy) {
        return TRUE;
    } else {
        return FALSE;
    }
}

double solve_linear(double b, double c) {
    return (-c/b);
}

void result(int num, double x1, double x2){
    switch (num) {
        case ZERO_ROOTS: printf("No solutions");
        break;
        case ONE_ROOT: printf("x = %lf", x1);
        break;
        case TWO_ROOTS: printf("x1 = %lf\nx2 = %lf", x1, x2);
        break;
        case INF_ROOTS: printf("Any number");
        break;
        default: printf("Error");

    }
}