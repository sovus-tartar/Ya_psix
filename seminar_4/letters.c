#include <stdio.h>

int main() {
    int a, b;

    for (a = 0; a < 128; a++) {
        printf("%c ", a);
        if (a % 16 == 0)   printf("\n");
         
    }
    printf("\n");
}