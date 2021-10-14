#include <stdio.h>

void fib_mod(unsigned long long x, unsigned long long m, unsigned long long *p, unsigned long long *f);

int main(void)
{
    unsigned long long m, x, p;
    unsigned long long f;
    scanf("%llu %llu", &x, &m);
    fib_mod(x, m, &p, &f);
    printf("%llu %llu", f, p);
}

void fib_mod(unsigned long long x, unsigned long long m, unsigned long long *p, unsigned long long *f)
{
    unsigned long long first, second;
    unsigned long long i;
    first = 0;
    second = 1;
    switch (x)
    {
    case 0ull:
    {
        *f = 0;
        break;
    }
    case 1ull:
    {
        *f = 1ull;
        break;
    }
    case 2ull:
    {
        *f = 2ull;
        break;
    }
    }

    for (i = 2; 1; i++)
    {
        unsigned long long temp = second;
        second = (second + first) % m;
        first = temp;
        /// printf("%llu %llu\n", first, second);
        if (first == 0 && second == 1)
        {
            *p = i - 1;
            break;
        }
    }

    x = x % (*p);
    first = 1;
    second = 1;
    for (i = 3; i <= x; i++)
    {
        unsigned long long temp = second;
        second = (second + first) % m;
        first = temp;

        if (i == x)
            *f = second;
    }
    
}