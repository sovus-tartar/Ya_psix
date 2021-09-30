#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    unsigned long long q, temp;
    assert(y != 0);

    while (y != 0)
    {
        temp = x;
        x = y;
        y = temp % y;
    }

    return x;
}

unsigned long long lcm(unsigned long long a, unsigned long long b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    unsigned long long n, i;
    unsigned long long l;
    scanf("%llu", &n);
    assert(n >= 2);
    l = 1;
    for (i = 2; i <= n; i++)
    {
        l = lcm(l, i);
    }
    printf("%llu", l);
    return 0;
}