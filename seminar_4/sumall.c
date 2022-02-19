#include <stdio.h>
#include <stdarg.h>
int sum(int n, ...) {
    int res, i;
    va_list args;
    res = 0;
    va_start(args, n);

    for(i = 0; i < n; i++) 
        res += va_arg(args, int);

    va_end(args);
    return res;
}

int main() {

    printf("%d", sum(5, 1, 2, 3, 4, 5));

}

