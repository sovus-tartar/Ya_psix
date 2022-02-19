#include <stdio.h>
#include <stdlib.h>
#define HASH_MAX 1000
#include <string.h>
#include <assert.h>

int count_hash(const char *s) {
    int len, hash, i;
    len = strlen(s);
    hash = 0;
    for(i = 0; i < len; i++) {
        hash += s[i];
    }

    return hash;
}

typedef int (*get_hash_t)(const char *s);


int ncollisions(char **strs, int n, get_hash_t f) {
    
    int i, col_count;

    int * arr;
    col_count = 0;
    arr = calloc(HASH_MAX, sizeof (int));
    assert(arr);

    for (i = 0; i < n; i++) {
        int c;
        arr[c = f(strs[i])] += 1;

        if (arr[c] > 1) 
            col_count++;
    }
    free(arr);
    return col_count;
}

int main() {

}