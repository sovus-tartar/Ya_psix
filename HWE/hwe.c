#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct sieve_t
{
    int n;
    unsigned char *mod1;
    unsigned char *mod5;
};

void fill_sieve(struct sieve_t *sv);
int is_prime(struct sieve_t *sv, unsigned n);

void test_is_prime() 
{
    unsigned n;
    struct sieve_t sv;

    sv.n = 1;

    sv.mod1 = calloc(1, sizeof(struct sieve_t)); //| 1 7 13 19 25 31 37 43 | 49
    sv.mod5 = calloc(1, sizeof(struct sieve_t)); //| 5 11 17 23 29 35 41 47 | 53
    
    scanf("%hhu", &sv.mod1[0]);
    scanf("%hhu", &sv.mod5[0]);

    for (n = 0; n < 48; n++)
    {
        printf("n = %u, is_prime = %d\n", n, is_prime(&sv, n));
    }

    free(sv.mod1);
    free(sv.mod5);
}

void sieve_output(struct sieve_t *sv)
{
    unsigned i;
    for (i = 0; i < (sv->n) * 48; i++)
    {
        printf(" i = %u, is_prime = %d\n", i, is_prime(sv, i));
    }
}

int main()
{
    int n;
    struct sieve_t sv;

    scanf("%d", &sv.n);
    //test_is_prime();
    sv.mod1 = calloc(sv.n, sizeof(struct sieve_t)); //| 1 7 13 19 25 31 37 43 | 49
    sv.mod5 = calloc(sv.n, sizeof(struct sieve_t)); //| 5 11 17 23 29 35 41 47 | 53
    fill_sieve(&sv);
    //sieve_output(&sv);

    free(sv.mod1);
    free(sv.mod5);
}

int is_prime(struct sieve_t *sv, unsigned n)
{
    unsigned m, k;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1; //for correct prime number output while using radical memory economy sieve
    if (n == 3)
        return 1;

    m = n % 6;
    n = n / 6;
    k = n / CHAR_BIT;

    if (m == 1)
    {
        return ((sv->mod1[k] >> (n % CHAR_BIT)) % 2 == 0);
    }

    if (m == 5)
    {
        return ((sv->mod5[k] >> (n % CHAR_BIT)) % 2 == 0);
    }

    return 0;
}

void set_composite(struct sieve_t *sv, unsigned n)
{
    unsigned m, k;

    m = n % 6;
    n = n / 6;
    k = n / CHAR_BIT;

    if (m == 1)
    {
        sv->mod1[k] = (sv->mod1[k]) | (1u << n % CHAR_BIT);
    }

    if (m == 5)
    {
        sv->mod5[k] = (sv->mod5[k]) | (1u << n % CHAR_BIT);
    }
}

void fill_sieve(struct sieve_t *sv)
{
    //3*8*n - max
    unsigned i, j;

    for (i = 0; i * i < (sv->n) * 48; i++)
    {
        if (is_prime(sv, i))
        {
            for (j = i * i; j < (sv->n) * 48; j += i)
            {
                set_composite(sv, j);
            }
        }
    }
}