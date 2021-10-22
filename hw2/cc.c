#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

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

unsigned long long pow_int(unsigned long long x, unsigned long long n)
{
    unsigned long long x0;
    x0 = x;

    for (n; n > 1; n--)
        x = x * x0;
    return x;
}

unsigned long long circ_transpos(unsigned long long N, unsigned long long num)
{
    if (num == 1)
        return N;
    return (N / 10 + (N % 10) * pow_int(10, num - 1));
}

unsigned long long digits_in_number(unsigned long long N)
{
    unsigned long long count;

    if (N == 0)
        return 1;
    for (count = 0; N != 0; count++)
        N = N / 10;
    return count;
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

int prime_check(unsigned long long num) ///
{
    int i;
    if (num == 0)
        return 0;
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

unsigned long long circ_prime_check(unsigned long long N)
{

    unsigned long long count, num;
    num = digits_in_number(N);
    assert(num > 0);
    ///printf("din = %llu\n", num);
    for (count = 0; count <= num; count++)
    {
        if (prime_check(N = circ_transpos(N, num)) == 0)
            return 0;
        ///printf("%llu\n", N);
    }
    return 1;
}

unsigned long long search_circ_prime(unsigned long long N)
{

    unsigned long long count;

    for (count = 0; ; count++)
    {
        if (((N - count) > 10) && (circ_prime_check(N - count) == 1))
            return N - count;
        if (circ_prime_check(N + count) == 1)
            return N + count;
    }
}

int main()
{
    unsigned long long N;

    scanf("%llu", &N);

    printf("%llu", search_circ_prime(N));
    //printf("%llu", circ_prime_check(N));
}