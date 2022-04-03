#include <stdio.h>
#include <math.h>
#include <assert.h>
struct answer_t
{
    double x;
    int i;
};

double epsilon;
// f(x) = a*x^2 +  b*x*cos(x) + c = 0 [-N; N]

int is_equal(double a, double b)
{
    return (fabs(a - b) < epsilon);
}

int fdiff_sign(double a, double b)
{
    return (signbit(a) != signbit(b));
}

double f_sign(double a)
{
    return signbit(a) ? -1.0 : 1.0;
}

double f(double a, double b, double c, double x)
{
    return a * pow(x, 2) * sin(x) + b * x * cos(x) + c;
}

struct answer_t dixotomia(double a, double b, double c, double left, double right)
{
    struct answer_t A;
    double fleft, fright;
    int i;

    i = 0;
    fleft = f(a, b, c, left);
    fright = f(a, b, c, right);

    if (!fdiff_sign(fleft, fright))
    {
        // printf("%lf\n", 0.0f);
        A.i = 0;
        A.x = 0.0f;
        return A;
    }

    while (!is_equal(left, right))
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
        i += 1;
    }

    // printf("%.5lf", left);
    A.x = left;
    A.i = i;
    return A;
}

struct answer_t ridders(double a, double b, double c, double left, double right)
{
    double temp, ftemp, fleft, fright, xnew;
    struct answer_t A;
    int i;
    i = 0;

    fleft = f(a, b, c, left);
    fright = f(a, b, c, right);
    if (!fdiff_sign(fleft, fright))
    {
        // printf("%lf\n", 0.0f);
        A.i = 0;
        A.x = 0.0f;
        return A;
    }

    while (1)
    {
        temp = (left + right) / 2;

        fleft = f(a, b, c, left);
        fright = f(a, b, c, right);
        ftemp = f(a, b, c, temp);
        printf("fleft = %lf\nfright = %lf\nftemp = %lf\n", fleft, fright, ftemp);

        //assert(sqrt(ftemp * ftemp - fleft * fright) > 0);

        xnew = temp + (temp - left) * f_sign(fleft - fright) * ftemp /
                          sqrt(fabs(ftemp * ftemp - fleft * fright));

        if (f_sign(f(a, b, c, xnew)) == -1.0)
            left = xnew;
        else
            right = xnew;

        printf("xnew = %lf\nf(xnew) = %lf\nleft = %lf\nright = %lf\n", xnew, f(a, b, c, xnew), left, right);
        i += 1;
        if (is_equal(f(a, b, c, xnew), 0.0))
        {
            A.x = xnew;
            A.i = i;
            return A;
        }
    }
}

int main()
{
    double a, b, c, N;
    struct answer_t D, R;
    scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &N, &epsilon);

    D = dixotomia(a, b, c, -N, N);
    R = ridders(a, b, c, -N, N);

    printf("%d %d\n", D.i, R.i);
}