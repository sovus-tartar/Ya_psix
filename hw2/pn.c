#include <stdio.h>

unsigned isprime(unsigned m) {
    int i;
    for(i = 2; i * i <= m; i++)
        if (m % i == 0) 
            return 0;
    return 1;
}

unsigned prime_seek(unsigned n) {
    unsigned i;
    unsigned k;
    k = 0;

    for(i = 2; k != n; i++) {
        if (isprime(i)) 
            k++;
    }
    return i - 1;
}

int main(void) {

    unsigned n;

    scanf("%u", &n);

    printf("%u", prime_seek(n));
}

