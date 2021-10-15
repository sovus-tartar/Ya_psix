#include <stdio.h>

int fib_arr(int *arr, int total) {
    
    int i;

    arr[0] = 1;
    arr[1] = 1;
    for (i = 1; total >= arr[i]; i++)
    {
        arr[i + 1] = arr[i] + arr[i - 1];
    }

    return i;
}

int next_turn(int total, int possible)
{

    int i;
    int max, min;
    int fib[100];

    if (possible >= total)
        return total;

    i = fib_arr(fib, total);
    
    min = max = total / fib[i - 1];

    for (i = i - 1; i > 0; i--)
    {
        if ((total / fib[i]) == 1)
            min = fib[i];
        total = total % fib[i];
    }

    if (possible >= min)
        return min;

    return 1;
}

void test(int a, int b, int expected) {
    int n;

    n = next_turn(a, b);

    if (n == expected)
        printf("%d %d %d PASS\n", a , b, n);
    else {
        printf("%d %d got: %d expected: %d  FAILED\n", a , b, n, expected);
    }
}

int main(void) {
    test(11, 10, 3);
    test(8, 6, 1);
    test(7, 2, 2);
    test(5, 4, 1);
    test(4, 2, 1);
    test(3, 2, 1);
    test(2, 2, 2);
}