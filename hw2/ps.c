#include <stdio.h>
#include <stdlib.h>

struct sieve_t {
  int n;
  char *s;
};

void fill_sieve(struct sieve_t *sv);

int nth_prime(struct sieve_t *sv, int N);

int main(void) {
    struct sieve_t sv;
    unsigned n;

    sv.s = calloc(100, sizeof(char));
    sv.n = 100;
    fill_sieve(&sv);
    printf("%d", nth_prime(&sv, 6));
}

void fill_sieve(struct sieve_t *sv) {
    int i, j;

    sv -> s[0] = 1;
    sv -> s[1] = 1;
    for (i = 2; i * i <= sv -> n; i++) {
        for (j = i * 2; j <= sv -> n; j += i) {
            sv -> s[j] = 1; 
            
        }
    }
}

int nth_prime(struct sieve_t *sv, int N) {
    int i, j;
    j = 0;

    for (i = 0; j != N; i++) 
        if (sv -> s[i] == 0) 
                j++; 
    return i - 1;
}