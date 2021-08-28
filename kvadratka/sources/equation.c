#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "../include/equation.h"

void coefficients_input(double* a, double* b, double* c){

    int correct_input_number = 0;

    assert(a);
    assert(b);
    assert(c);

    while (correct_input_number != 3) {
        correct_input_number = 0;

        printf("\nax^2 + bx + c = 0\n");

        correct_input_number = variable_input(a, 'a') +
                variable_input(b, 'b') + variable_input(c, 'c');

        if (correct_input_number != 3) {
            printf("\nWrong input. Try again\n");

        }

        clean_buffer();
    }
}

int equation_solver(const double a, const double b, const double c, double* x1, double* x2){

    double dis = NAN, sqrt_dis = NAN;
    double denom_coef = 2 * a; //denominator coefficient is 2 * a

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 !=NULL);

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

            *x1 = (-b + sqrt_dis) / denom_coef;
            *x2 = (-b - sqrt_dis) / denom_coef;

            return TWO_ROOTS;

        } else if (dis < 0) {
            return ZERO_ROOTS;

        } else {
            *x1 = -b / denom_coef;
            return ONE_ROOT;
        }
    }
}

char is_equal(const double val_1, const double val_2) {

    assert((isfinite(val_1)) || (isnan(val_1)));
    assert((isfinite(val_2)) || (isnan(val_2)));

    if ((fabs(val_1 - val_2) < ACCURACY) || ((isnan(val_1)) && (isnan(val_2)))) {
        return TRUE;
    } else {
        return FALSE;
    }
}

double solve_linear(const double b, const double c) {

    assert(isfinite(b));
    assert(isfinite(c));

    double x = - c / b;
    return x;
}

void print_roots(const int root_number, const double x1, const double x2){

    assert((isfinite(x1)) || (isnan(x1)));
    assert((isfinite(x2)) || (isnan(x2)));

    switch (root_number) {
        case ZERO_ROOTS:
            printf("No solutions\n");
            break;
        case ONE_ROOT:
            printf("x = %lf\n", x1);
            break;
        case TWO_ROOTS:
            printf("x1 = %lf\nx2 = %lf\n", x1, x2);
            break;
        case INF_ROOTS:
            printf("Any number\n");
            break;
        default:
            printf("Unknown Error: unexpected number of roots\n");

    }
}

void clean_buffer(void){
    while (getchar () != '\n') ;
}

void equation_output(const double a, const double b, const double c){
    assert(a);
    assert(b);
    assert(c);

    printf("%lf * x^2 + %lf * x + %lf = 0\n", a, b, c);
}

int variable_input(double* coefficient, const int coef_letter){

    assert(coefficient);
    char input[40];

    printf("Enter %c:", coef_letter);

    scanf("%s", input);

    if (input_check(input)) {
        sscanf(input, "%lf", coefficient);
        return 1;
    } else return 0;


}


void user_interface(void){

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int root_number = 0;
    int user_input = 'y';

    while (user_input == 'y') {

#ifdef DEBUG                    //For debugging purposes
        break;
#endif

        coefficients_input(&a, &b, &c);
        equation_output(a, b, c);
        root_number = equation_solver(a, b, c, &x1, &x2);
        print_roots(root_number, x1, x2);

        printf("Do you want to try again?(y/any)\n");

        user_input = getchar();

    }
}

void program_exit(void){
    printf("Press any key to close the program");

    clean_buffer();
    getchar();
}

int input_check(char* input){
    int error_count = 0;

    for (int symb_count = 0; symb_count < strlen(input); symb_count++){
        if (!(isdigit(input[symb_count]) || (input[symb_count] == '.'))) {
            error_count++;
        }
    }

    if (error_count) {
        return FALSE;
    } else {
        return TRUE;
    }

}

