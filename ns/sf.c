#include <stdio.h>

unsigned translate_fib(unsigned);

int main() {
    unsigned x;
    scanf("%u", &x);

    translate_fib(x);

}

unsigned translate_fib(unsigned x) {
    unsigned i, fib[100], first, second;
    fib[0] = 1;
    fib[1] = 1;
    for(i = 1; x > fib[i] ; i++){
        fib[i + 1] = fib[i] + fib[i - 1];
    }

    for(i; i > 0; i--)
        if (x <= fib[i]) {
            printf("%u", x / fib[i]);
            x = x % fib[i];
        }

    
}