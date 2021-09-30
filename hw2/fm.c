#include <stdio.h>

unsigned long long  fib_mod(unsigned x, unsigned m);

int main(void){
    int x, m;
    scanf("%u %u", &x, &m);
    printf("%llu\n", fib_mod(x, m));
}

unsigned long long fib_mod(unsigned x, unsigned m){
    unsigned long long first, second;
    int i;
    first = 0;
    second = 1;
    switch(x){
        case 0: return 0ull;
        case 1: return 1ull;
        case 2: return 2ull;
        default:
            for(i = 2; i <= x; i++){
            unsigned long long temp = second;
            second = (second + first) % m;
            first = temp;
            }

    return second;
    }
}
