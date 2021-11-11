#include <stdio.h>

int bit_comp(unsigned long long a, unsigned long long b)
{
    int count;
    count = 0;
    while (a > 0)
    {
        unsigned long long a_mod, b_mod;

        a_mod = a % 2;
        b_mod = b % 2;
        if (a_mod > b_mod)
            count++;
        a = a / 2;
        b = b / 2;
        //printf("ble %d", count);
    }

    return count;
}

int main()
{
    unsigned long long a, b;

    scanf("%llu%llu", &a, &b);

    printf("%d", bit_comp(a, b));
}