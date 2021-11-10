#include <stdio.h>

int main() {
    int nday, N;

    scanf("%d%d", &N, &nday);

    printf("%d", (N - nday)  / 7 +  1);
}