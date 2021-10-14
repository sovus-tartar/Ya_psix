//Program PE//

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct sieve_t {
  int n;
  unsigned char *s;
};  

int is_prime(struct sieve_t *sv, unsigned n)
{
    return (((sv -> s[n / CHAR_BIT]) >> (n % CHAR_BIT)) % 2 == 0);
}

void set_composite(struct sieve_t *sv, unsigned n)
{
    sv->s[n / CHAR_BIT] = (sv->s[n / CHAR_BIT]) | (1u << (n % CHAR_BIT));
    
}

void fill_sieve(struct sieve_t *sv)
{
    int i, j;

    sv->s[0] = 3; // 3 = 11

    for (i = 2; i * i <= sv -> n * CHAR_BIT; i++)    
        if (is_prime(sv, i))
            for (j = i * i; j <= sv -> n * CHAR_BIT; j += i)
                set_composite(sv, j);
}

int nth_prime(struct sieve_t *sv, unsigned n)
{
    int i, j;
    j = 0;

    for (i = 0; j != n; i++)
        if (sv->s[i] == 0)
            j++;
    return i - 1;
}

int main(void)
{
    struct sieve_t sv;
    unsigned n;
    //scanf("%u", &n);
    n = 100;
    sv.s = (char *)calloc(n, sizeof(char));
    sv.n = n;
    fill_sieve(&sv);
    printf("%x\n", sv.s[1]);
    free(sv.s);
}