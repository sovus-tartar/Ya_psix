#include <stdio.h>

void matrix_pow(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
void matrix_square(unsigned* x00, unsigned* x01, unsigned* x10, unsigned* x11);

int main(){
    unsigned x00, x01, x10, x11, n, m;

    scanf("%u %u %u %u %u %u", &x00, &x01, &x10,&x11, &n, &m);

    matrix_pow(x00, x01, x10, x11, n, m);
}

void matrix_pow(unsigned x00, unsigned x01, unsigned x10, unsigned x11, unsigned n, unsigned m) {
    
    unsigned i, x00_old, x01_old, x10_old, x11_old;

    x00_old = x00;
    x01_old = x01;
    x10_old = x10;
    x11_old = x11;

    for(i = 2; i <= n; i++) {
        unsigned x00_copy, x01_copy, x10_copy, x11_copy;

        x00_copy = x00;
        x01_copy = x01;
        x10_copy = x10;
        x11_copy = x11;

        x00 = x00_copy * x00_old + x01_copy * x10_old;
        x01 = x00_copy * x01_old + x01_copy * x11_old;
        x10 = x10_copy * x00_old + x11_copy * x10_old;
        x11 = x10_copy * x01_old + x11_copy * x11_old;

        x00 = x00 % m;
        x01 = x01 % m;
        x10 = x10 % m;
        x11 = x11 % m;

    }

    printf("%u %u %u %u\n", x00, x01, x10, x11);
}

