#include <stdio.h>

#define N 100
struct _Decimal {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0};    // представление 0 в виде структуры

int is_div11 (const Decimal * a) {
    int i, even, not_even;
    even = 0;
    not_even = 0;
    

    for(i = 0; i <= a -> n; i+=2) {
        even += a->a[i];
        printf("bla1");
    }

    for(i = 1; i <= a -> n; i+=2) {
        not_even += a->a[i];
        printf("bla2");
    }

    if (((even - not_even) % 11) == 0) 
        return 1;

    return 0;
}

int main(){
    Decimal a = {{3, 4, 1}, 2};  // 143 (делится на 11)
    Decimal b = {{3, 1}, 1};     // 13 (не делится на 11)
    int res;
    
    res = is_div11(&a);         // res = 1
    printf("%d\n", res);
    
    res = is_div11(&b);         // res = 0
    printf("%d\n", res);
    
    return 0;
}