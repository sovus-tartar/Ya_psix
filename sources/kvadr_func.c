#include "../include/kvadr_head.h"

void enter(double* a, double* b, double* c){

    int i = 0;

    assert(a > 0);
    assert(b > 0);
    assert(c > 0);

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

int equation_solver(double a, double b, double c, double* x1, double* x2){

    double dis = NAN, sqrt_dis = NAN;

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 > 0);
    assert(x2 > 0);

    if ((is_equal(a, 0)) && (is_equal(b, 0)) && (is_equal(c, 0))){ //a = b = c = 0
        return INF_ROOTS;
    } else if ((is_equal(a, 0)) && (is_equal(b, 0))){// a = b = 0
        printf("%lf %lf", a, b);
        return ZERO_ROOTS;
    } else if (is_equal(a, 0)) {  //a = 0 - linear equation
        *x1 = solve_linear(b, c);
        return ONE_ROOT;
    } else { //square equation solve

        dis = b * b - 4 * a * c;

        if (dis > 0) {
            sqrt_dis = sqrt(dis);
            *x1 = (-b + sqrt_dis) / (2 * a);
            *x2 = (-b - sqrt_dis) / (2 * a);

            return TWO_ROOTS;

        } else if (dis < 0) {
            return ZERO_ROOTS;

        } else {
            *x1 = -b / (2 * a);
            return(ONE_ROOT);
        }
    }
}

char is_equal(double val_1, double val_2) {
    if (fabs(val_1 - val_2) < accuracy) {
        return TRUE;
    } else {
        return FALSE;
    }
}

double solve_linear(double b, double c) {
    double x = - c / b;
    return (x);
}

void result(int num, double x1, double x2){
    switch (num) {
        case ZERO_ROOTS: printf("No solutions\n");
        break;
        case ONE_ROOT: printf("x = %lf\n", x1);
        break;
        case TWO_ROOTS: printf("x1 = %lf\nx2 = %lf\n", x1, x2);
        break;
        case INF_ROOTS: printf("Any number\n");
        break;
        default: printf("Error\n");

    }
}