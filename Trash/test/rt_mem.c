#include <stdio.h>
#include <stdlib.h>
struct _Decimal
{
    char *a;           // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;    // наибольшая степень десяти
    unsigned int size; // размер выделенной динамической памяти в а (можно это поле не использовать).
};
typedef struct _Decimal Decimal;

Decimal *set_int(int a)
{

    Decimal *num;

    num = calloc(1, sizeof(Decimal));
    num->a = calloc(3, sizeof(int));

    num->a[0] = 7;
    num->a[1] = 4;
    num->a[2] = 5;

    num->n = 2;
    return num;
}

Decimal *div10n(const Decimal *a, unsigned int n)
{
    int j;
    unsigned i;
    Decimal * temp;
    temp = calloc(1, sizeof(Decimal));
    temp -> a = calloc(a->n + 1, sizeof(int)); 
    if (a -> n < n) 
        return temp;
    *temp = *a;
    
    for (i = 0; i <= a->n + 1 - n; i++)
    {
        temp->a[i] = a->a[i + n];
    }

    if ((a->n - (int)n) >= 0)
        temp->n = a->n - (int)n;
    else
        temp->n = 0;
    return temp;
}

void print(Decimal *a)
{
    int i;
    printf("\n");
    for (i = a->n; i >= 0; i--)
        printf("%d", a->a[i]);
}
int main()
{
    Decimal *a;
    Decimal *res;

    a = set_int(147); // 147 is {{7, 4, 1}, 2};
    print(a);
    res = div10n(a, 4); // res = a/100 = 147/100 = 1

    print(res); // print 1
    printf("\n%d", res->n);
    printf("\n");

    // надо освободить память

    return 0;
}