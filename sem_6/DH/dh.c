#include <stdio.h>
#include <math.h>
const double epsilon = 0.00001;
// f(x) = a*x^2 +  b*x*cos(x) + c = 0 [-N; N]

int fdiff_sign(double a, double b)
{
    return (signbit(a) != signbit(b));
}

double f(double a, double b, double c, double x)
{
    return a * pow(x, 2) * sin(x) + b * x * cos(x) + c;
}

double solve_eq(double a, double b, double c, double left, double right)
{

    double fleft, fright;

    fleft = f(a, b, c, left);
    fright = f(a, b, c, right);

    if (!fdiff_sign(fleft, fright))
    {
        printf("%lf\n", 0.0f);
        return 0.0f;
    }

    while (fabs(left - right) > epsilon)
    {
        double temp, ftemp;
        temp = (left + right) / 2;
        ftemp = f(a, b, c, temp);

        // printf("fleft = %lf left = %lf fright = %lf right = %lf ftemp = %lf temp = %lf \n", fleft, left, fright, right, ftemp, temp);

        if (fdiff_sign(fleft, ftemp))
        {
            fright = ftemp;
            right = temp;
        }
        else
        {
            fleft = ftemp;
            left = temp;
        }
    }

    printf("%.5lf", left);

    return left;
}

int main()
{
    double a, b, c, N;

    scanf("%lf%lf%lf%lf", &a, &b, &c, &N);

    solve_eq(a, b, c, -N, N);
}