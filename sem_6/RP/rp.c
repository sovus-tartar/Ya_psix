#include <stdio.h>
#include <fenv.h>
#include <math.h>
#include <assert.h>
#include <string.h>

void print_exp(float a)
{

    unsigned u;

    memcpy(&u, &a, sizeof(unsigned));

    u = (u >> 23) & 0b011111111;

    printf("0x%x ", u);
}

void print_fract(float a)
{
    unsigned u;

    memcpy(&u, &a, sizeof(unsigned));

    u = ((u << 9) >> 9);

    printf("0x%x ", u);
}

void print_exp_fract(float a)
{
    print_exp(a);
    print_fract(a);
}

int main()
{
    int a, b;
    float f, g, h;

    scanf("%d%d", &a, &b);

    assert(fabs(b) > 0);

    if (((a >= 0) && (b > 0)) || ((a <= 0) && (b < 0)))
    {
        fesetround(FE_DOWNWARD);
        f = (float)a / b;
        fesetround(FE_UPWARD);
        g = (float)a / b;

        if (f == g)
        {
            print_exp_fract(f);
            printf("\n");
            return 0;
        }
    }
    else
    {
        unsigned h, k;
        fesetround(FE_UPWARD);
        f = (float)a / b;
        memcpy(&h, &f, sizeof(float));
        h += 1;
        memcpy(&f, &h, sizeof(float));
        //printf("%f\n", f);
        fesetround(FE_DOWNWARD);
        g = (float)a / b;
        memcpy(&k, &g, sizeof(float));
        k += 1;
        memcpy(&g, &k, sizeof(float));
        //printf("%f\n", g);
        

        if (f == g)
        {
            print_exp_fract(f);
            printf("\n");
            return 0;
        }
    }
    print_exp_fract(f);
    print_exp_fract(g);
    printf("\n");
}
