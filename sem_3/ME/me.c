#include <stdlib.h>
#include <stdio.h>


int majority_element(const int *parr, int len) {
    int i, count, majority;

    count = 1;
    majority = parr[0];

    for(i = 1; i < len; i++) {
        if (majority == parr[i])
            count += 1;
        else {
            count -= 1;
        }

        if(count == 0) {
            majority = parr[i];
            count = 1;
        }
    }

    if (count != 1)
        return majority;

    return -1;
}

void fill_arr(int * parr, int N) {
    int i;
    for(i = 0; i < N; i++) {
        scanf("%d", parr + i);
    }
}

int main() {
    int N, i;
    int * parr;
    scanf("%d", &N);
    
    parr = calloc(N, sizeof(int));
    fill_arr(parr, N);


    printf("%d\n", majority_element(parr, N));

    free(parr);
}