#include <stdio.h>

typedef union foo {
    float num;
    int bits;
} FLOAT;

FLOAT inv_odd_bits_d(FLOAT a) {

    a.bits = a.bits ^ 0x2AAAAA;
    return a;
}

int main() {

    FLOAT a;

    scanf("%f", &a.num);

    a = inv_odd_bits_d(a);

    printf("%.5f\n", a.num);
}