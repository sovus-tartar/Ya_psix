#include <stdio.h>
#include <math.h>

double deriv_f(double a, double b, double x) {
    return(a * (2 * x * sin(x) + cos(x) * x * x) + b * (cos(x) - x * sin(x)));
}

double f(double a, double b, double c, double x) {
    return (a * x * x * sin(x) + b * x * cos(x) + c);
}

const double epsilon = 0.00001;

int is_equal(double a, double b) {
    return ((fabs(a - b) <= epsilon) ? 1 : 0);
}



double newton(double a, double b, double c, double x) {

    int i;

    for(i = 0; i < 4000; i++) {
        double der;
        if (is_equal(der = deriv_f(a, b, x), 0.0))
            return 0;
        //printf("der = %lf\n", deriv_f(a,b,x));
        x = x - (f(a, b, c, x) / der);
        
        //printf("f = %lf\n", f(a,b,c,x));
        if (is_equal(f(a, b, c, x), 0.0))
            return x;
        
        //printf("%lf\n", x);
    }


    return 0.0;
}

int main() {
    double a, b, c, x;

    scanf("%lf%lf%lf%lf", &a, &b, &c, &x);

    printf("%lf\n", newton(a, b, c, x));


    
}