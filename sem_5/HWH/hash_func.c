#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


#include "hash_header.h"

int const q = 10; // hash("abc") == (q^2 * 'a' + q^1 * 'b' + q^0 * 'c') % p
int const p = 1000;

void clear_buffer()
{
    char c;
    while (c = getchar() != '\n');
}

int count_hash(char *str)
{
    int n, i, h;

    n = strlen(str);
    h = 0;

    for (i = 0; i < n; i++)
        h += ((q ^ (n - i)) * str[i]) % p;

    return h;
}

hashmap *read_dict(int n, char *str)
{
    int i, j;
    hashmap *top, *curr;
    clear_buffer();

    top = calloc(1, sizeof(hashmap));
    assert(top != NULL);
    top->ptr = str;
    curr = top;

    for (i = 0; i < n; i++)
    { //read to array
        str[i] = getchar();

        if (str[i] == ' ')
        {
            hashmap *temp;

            str[i] = '\0';

            temp = calloc(1, sizeof(hashmap));
            curr->next = temp;
            curr = curr->next;

            curr->ptr = str + (i + 1);
        }
    }

    str[n] = '\0';

    curr = top; //count hash of words in dictionary

    while (curr != NULL)
    {
        curr->hash = count_hash(curr->ptr);
        curr = curr->next;
    }

    return top;
}

void delete_dict(hashmap *top)
{
    hashmap *curr, *temp;
    curr = top;
    while (curr != NULL)
    {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
}

void seek_words(hashmap *word, hashmap *text)
{
    assert(word != NULL);
    assert(text != NULL);

    while (word != NULL)
    {
        int target, count;
        hashmap *curr;
        count = 0;

        target = word->hash;
        curr = text;

        while (curr != NULL)
        {

            if ((curr->hash == target) && (strcmp(curr->ptr, word->ptr) == 0))
                count++;

            curr = curr->next;
        }

        printf("%d ", count);

        word = word->next;
    }
}
