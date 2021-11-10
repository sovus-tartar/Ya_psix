#include <stdio.h>
void toMiddle(int *x1, int *x2, int middle)
{

    int x3, x4;
    float M;

    M = ((float)*x2 - (float)*x1) / 2;

    //printf("%f\n", M);

    x3 = (int)((float)middle - M + !!((float)middle / M) * !!((*x2 - *x1) % 2));

    x4 = (int)((float)middle + M + !!((M + M + (float)middle) / M) * !!((*x2 - *x1) % 2));

    printf("%d %d\n", x3, x4);
}

int main()
{

    int x1, x2, middle;

    scanf("%d %d %d", &x1, &x2, &middle);

    toMiddle(&x1, &x2, middle);

    return 0;
}