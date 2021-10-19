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

struct formula formula_check(int N);
struct formula {
    int a;
    int b;
    int i;
} ;

int main()
{
    int N;
    struct formula out;

    scanf("%d", &N);

    out = formula_check(N);

    printf("%d %d %d", out.a, out.b, out.i);
}

struct formula formula_check(const int N) {

    int a, b, i, max;
    struct formula koef = {0, 0, 0};

    max = 0;

    for (a = -N; a < N; a++) //a++ == a = a + 1
        for (b = -N; b < N; b++) {//0 42 0>42

            for (i = 0; prime_check(i * i + a * i + b) == 1; i++);

            ///printf("i = %d a = %d b = %d\n", i, a, b, N);
            
            if (i > koef.i) {
                koef.i = i;
                koef.a = a;
                koef.b = b;
            } 
                
        }
    return koef;
}

int prime_check(unsigned long long num) ///
{
    int i;
    if (num == 0) return 0;
    srand(time(NULL));

    for (i = 1; i <= 20; i++)
    {
        unsigned long long temp;
        while (gcd(temp = rand(), num) != 1);

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