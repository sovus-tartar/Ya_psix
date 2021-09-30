#include <stdio.h>

unsigned long long fib_mod(unsigned x, unsigned m, unsigned* p);

int main(void){
    unsigned m, x, p;
    scanf("%u %u", &x, &m);
    
    printf("%llu %u", fib_mod(x % p, m, &p), p);
}

unsigned long long fib_mod(unsigned x, unsigned m, unsigned* p){
    unsigned long long first, second;
    unsigned i;

    *p = 0;
    first = 0;
    second = 1;

    switch(x){
        case 0: return 0ull;
        case 1: return 1ull;
        case 2: return 2ull;
        default:
            for(i = 2; *p = 0; i++){
            unsigned long long temp = second;
            second = (second + first) % m;
            first = temp;
            if (second == 1 && first == 0) *p = i - 1;
            }

    for(i = 2; i <= x & *p; i++){
            unsigned long long temp = second;
            second = (second + first) % m;
            first = temp;
            }

    return second;
    }
}

