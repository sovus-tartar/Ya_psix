#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void read(int *p, int m)
{
    int i;

    for (i = 0; i < m; i++)
        scanf("%d", &p[i]);
}

void mult(int *mp, int m, int *np, int n, int *kp)
{
    int i, q;

    for (i = 0; i < m; i++)
        for (q = 0; q < n; q++)
            kp[i + q] += mp[i] * np[q];
}

int main()
{
    int m, n, i;
    int *mp, *np, *kp;
    scanf("%d%d", &m, &n);

    mp = calloc(m, sizeof(int));
    np = calloc(n, sizeof(int));
    kp = calloc(m + n - 1, sizeof(int));

    assert(mp != NULL && np != NULL && kp != NULL);

    read(mp, m);
    read(np, n);

    mult(mp, m, np, n, kp);

    for (i = 0; i < m + n - 1; i++)
    {
        if (!(i == m + n - 1 && kp[i] == 0))
            printf("%d ", kp[i]);
    }

    free(mp);
    free(np);
    free(kp);
}
