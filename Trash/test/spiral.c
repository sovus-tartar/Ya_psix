#include <stdio.h>

unsigned long long sum(int n)
{
    unsigned long long k, sum;
    sum = 1;
    for (k = 3; k <= n; k = k + 2)
    {
        unsigned long long sq_k, delta;
        sq_k = k * k;
        delta = k - 1;
        sum += sq_k + (sq_k - delta) + (sq_k - 2 * delta) + (sq_k - 3 * delta);
    }

    return sum;
}

int main()
{
    unsigned long long n;

    scanf("%llu", &n);

    printf("%llu", sum(n));

    return 0;
}