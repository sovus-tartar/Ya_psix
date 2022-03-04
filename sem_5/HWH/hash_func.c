#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "hash_header.h"

int const q = 10;   // hash("abc") == (q^2 * 'a' + q^1 * 'b' + q^0 * 'c') % p
int const p = 1000; // elements of array in hash-table

void _clear_buffer()
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
        h = (h + ((q ^ (n - i)) * str[i])) % p;

    return h;
}

bucket *strings_to_hashmap(int n, char *str) 
{
    bucket *table;
    int i, j;

    _clear_buffer();

    table = calloc(p, sizeof(bucket));
    table[0].ptr = str;

    assert(table != NULL);

    j = 0;
    for (i = 0; i < n; i++)
    { // read to array
        str[i] = getchar();
        j += 1;
        if (str[i] == ' ')
        {
            int hash;
            str[i] = '\0';
            hash = count_hash(str + i - j + 1);
            add_bucket(&table[hash], str + i - j + 1);

            j = 0;
        }
    }

    add_bucket(table + count_hash(str + i - j), str + i - j);

    return table;
}

bucket *add_bucket(bucket *top, char *str)
{

    while (top->next != NULL)
        top = top->next;

    top->next = calloc(1, sizeof(bucket));
    top->ptr = str;

    return top->next;
}

void show_hashmap(bucket *table)
{
    int i;

    for (i = 0; i < p; i++)
    {
        printf("hash = %d, addr = %p string = %s  next = %p | ", i, table, (table + i)->ptr, (table + i)->next);
        if ((table + i)->next != NULL)
        {
            bucket
                *temp;
            temp = (table + i)->next;

            while (temp != NULL)
            {
                printf("addr = %p string = %s next = %p| ", temp, temp->ptr, temp->next);
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

int hashmap_seek(bucket *table, char *target)
{
    int word_hash, count;
    bucket
        *cell;
    count = 0;
    word_hash = count_hash(target);
    cell = &table[word_hash];

    while (cell->next != NULL)
    {
        if (strcmp(target, cell->ptr) == 0)
        {
            count += 1;
        }
        cell = cell->next;
    }

    return count;
}

void delete_hashmap(bucket *table)
{
    int i;
    bucket
        *curr;

    for (i = 0; i < p; i++)
    {
        curr = table + i;

        if (curr->next != NULL)
        {
            bucket
                *temp;
            curr = curr->next;
            while (curr->next != 0)
            {
                temp = curr->next;
                free(curr);
                curr = temp;
            }
        }
    }
}