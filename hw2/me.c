#include <stdio.h>
int majority_element(const int *parr, int len);
int main()
{
    int parr[10] = {1, 2, 3, 1, 2, 1};
    int len;
    len = 6;

    printf("%d", majority_element(parr, len));
}

int majority_element(const int *parr, int len)
{

    int m1, m2;
    int k;

    for (k = 0; k < len; ++k){
        printf("%d ", parr[k]);
    }

    printf("\n");

    if (len == 1)
        return *parr;

    if (len != 2)
    {
        int i, m1_count, m2_count;
        m1 = majority_element(parr, len / 2);
        m2 = majority_element(parr + len / 2, len / 2);

        for (i = 0; i < len; i++)
        {
            if (parr[i] == m1)
                m1_count++;
            if (parr[i] == m2)
                m2_count++;
        }
        if (m1_count > m2_count)
            return m1;
        else if (m2_count > m1_count)
            return m2;
        else
            return -1;
    }
    else if (parr[0] == parr[1]) return *parr;
        else
            return -1;
}