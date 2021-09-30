#include <stdio.h>

void translate_fib(unsigned);

int main()
{
    unsigned x;
    scanf("%u", &x);

    translate_fib(x);
}

void translate_fib(unsigned x)
{
    unsigned i, fib[100];
    fib[0] = 1;
    fib[1] = 1;
    for (i = 1; x >= fib[i]; i++)
    {
        fib[i + 1] = fib[i] + fib[i - 1];
    }

    for (i = i - 1; i > 0; i--)
    {
        printf("%u", x / fib[i]);
        x = x % fib[i];
    }
}