#include <stdio.h>
#include <assert.h>
int msb(unsigned long long);

int main(void) {
    unsigned long long a;

    scanf("%llu", &a);

    printf("%d", msb(a));
}

int msb(unsigned long long a) {
    int i, temp;
    
    assert(a >= 0);

    if (a == 0) return -1;
    
    for(i = 0; a > 0 ; i++) {
        ///printf("%llu\n", a);
        temp = a % 2;
        a = a >> 1;
    }

    return i - 1;
}