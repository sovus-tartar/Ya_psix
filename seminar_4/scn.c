#include <stdio.h>

int main() {
    int i, d;
    char str[1025] = "";
    char c;
    d = 0;

    for(i = 0; (c = getchar()) != EOF ; i++) {
        d += c;
    }

    printf("%d\n", d);
}