#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int count_step(int *coins, int val, int n);
int min_arr (int * arr, int n);

int main()
{
    int val, n, *coins;
    int i;
    scanf("%d%d", &val, &n);

    coins = calloc(val + 1, sizeof(int));
    assert(coins != NULL);
    for (i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    printf("%d\n", count_step(coins, val, n));

    free(coins);
}

int count_step(int *coins, int val, int n)
{

    int i, j, *arr, z;

    arr = calloc(val + 1, sizeof(int));
    assert(arr != NULL);
    for (i = 1; i <= val; i++)
    {
        int *temp, k;
        temp = calloc(n, sizeof(int));
        assert(temp != NULL);
        for (j = 0; j < n; j++)
        {
            if ((i - coins[j] >= 0) && (val - coins[j] >= 0))
            {
                temp[j] = arr[i - coins[j]] + 1;
            }
        }

        k = min_arr(temp, n)
        arr[i] = k;
        val -= coins[k];

        free(temp);
    }

    z = arr[val];
    free(arr);
    return z;
}

int min_arr (int * arr, int n) {
    int i, t, i_min;
    assert(n > 0);
    assert(arr != NULL);
    
    t = arr[0];
    i_min = 0;

    for(i = 1; i < n; i++){
        if ((t > arr[i]) && (arr[i] > 0)) {
            t = arr[i];
            i_min = t;
        }
    }

    return i_min;
}