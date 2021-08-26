#include "sources/kvadr_head.h"
//#define DEBUG
int main(void) {

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 =NAN;
    int num;
    char i = 'y';

    printf("Square equations solver\n");

    while (i == 'y') {

#ifdef DEBUG
        break;
#endif

        enter(&a, &b, &c);

        num = equation_solver(a, b, c, &x1, &x2);
        result(num, x1, x2);

        printf("Do you want to try again?(y/any)\n");
        getchar();
        i = getchar();

    }
#ifdef DEBUG
    unit_test();
#endif

    printf("Press any key to close");
    getchar();
    getchar();

    return 0;
}
