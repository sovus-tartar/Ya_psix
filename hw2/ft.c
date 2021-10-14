#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

unsigned long long iabs(unsigned long long);
unsigned long long eu_mod(unsigned long long, unsigned long long);
unsigned long long gcd(unsigned long long, unsigned long long);
int prime_check(unsigned long long);
unsigned long long pow_mod(unsigned long long n, unsigned long long k, unsigned long long m);

int main()
{

    unsigned long long num;

    scanf("%llu", &num);

    printf("%d", prime_check(num));

    return 0;
}

int prime_check(unsigned long long num)
{
    int i;
    srand(time(NULL));

    for (i = 1; i <= 20; i++)
    {
        unsigned long long temp;
        while (gcd(temp = rand(), num) != 1)
            ;

        if (pow_mod(temp, num - 1, num) != 1)
        {
            return 0;
        }
    }

    return 1;
}

unsigned long long pow_mod(unsigned long long n, unsigned long long k, unsigned long long m)
{
    unsigned long long mult = n % m;
    unsigned long long prod = 1;
    while (k > 0)
    {
        if ((k % 2) == 1)
        {
            prod = (prod * mult) % m;
            k = k - 1;
        }
        mult = (mult * mult) % m;
        k = k / 2;
    }
    return prod;
}

unsigned long long iabs(unsigned long long x)
{
    return (x < 0) ? -x : x;
}

unsigned long long eu_mod(unsigned long long x, unsigned long long y)
{
    unsigned long long r;
    assert(y != 0);
    r = x % y;
    if (r < 0)
        r += iabs(y);
    return r;
}
unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    unsigned long long q, temp;
    assert(y != 0);

    while (y != 0)
    {
        temp = x;
        x = y;
        y = eu_mod(temp, y);
    }

    return x;
}