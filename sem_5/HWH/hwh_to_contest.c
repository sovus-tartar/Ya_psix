#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct hashmap_t
{
    char *ptr;
    struct hashmap_t *next;
} hashmap;

int const q = 10;   // hash("abc") == (q^2 * 'a' + q^1 * 'b' + q^0 * 'c') % p
int const p = 1000; // elements of array in hash-table

int count_hash(char *str);
hashmap *read_dict(int n, char *str);
void delete_dict(hashmap *table);
hashmap *hashmap_add(hashmap *top, char *str);
char **read_words(int n, int n_words, char *str_arr);
void clear_buffer();
int seek_words(hashmap *table, char *target);
void show_hashmap(hashmap *table);

void clear_buffer()
{
    char c;
    while (c = getchar() != '\n')
        ;
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

hashmap *read_dict(int n, char *str)
{
    hashmap *table;
    int i, j;

    clear_buffer();

    table = calloc(p, sizeof(hashmap));
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
            hashmap_add(&table[hash], str + i - j + 1);

            j = 0;
        }
    }

    hashmap_add(table + count_hash(str + i - j), str + i - j);

    return table;
}

hashmap *hashmap_add(hashmap *top, char *str)
{

    while (top->next != NULL)
        top = top->next;

    top->next = calloc(1, sizeof(hashmap));
    top->ptr = str;

    return top->next;
}

void show_hashmap(hashmap *table)
{
    int i;

    for (i = 0; i < p; i++)
    {
        printf("hash = %d, addr = %p string = %s  next = %p | ", i, table, (table + i)->ptr, (table + i)->next);
        if ((table + i)->next != NULL)
        {
            hashmap *temp;
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

int seek_words(hashmap *table, char *target)
{
    int word_hash, count;
    hashmap *cell;
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

char **read_words(int n, int n_words, char *str_arr)
{

    int i, j;
    char **ptr_arr;
    clear_buffer();

    ptr_arr = calloc(n, sizeof(char *));

    j = 1;
    ptr_arr[0] = str_arr;
    for (i = 0; i < n_words; i++)
    {

        str_arr[i] = getchar();

        if (str_arr[i] == ' ')
        {
            str_arr[i] = '\0';
            ptr_arr[j] = str_arr + i + 1;
            j++;
        }
    }
    str_arr[n_words] = 0;

    //for (i = 0; i < n; i++)
    //    printf("%s %p\n", ptr_arr[i], ptr_arr + i - 1);
    assert(j == n);
    return ptr_arr;
}

void delete_dict(hashmap *table)
{
    int i;
    hashmap *curr;

    for (i = 0; i < p; i++)
    {
        curr = table + i;

        if (curr->next != NULL)
        {
            hashmap *temp;
            curr = curr->next;
            while (curr->next != 0)
            {
                temp = curr->next;
                free(curr);
                curr = temp;
            }
        }
    }

    free(table);
}

int main()
{
    hashmap *text;
    char *str_text, **ptr_arr, *str_arr;
    int n_text, n, n_words, i;

    scanf("%d", &n);
    scanf("%d", &n_text);

    str_text = calloc(n_text + 1, sizeof(char));
    assert(str_text != NULL);
    text = read_dict(n_text, str_text);

    scanf("%d", &n_words);
    str_arr = calloc(n_words + 1, sizeof(char));

    ptr_arr = read_words(n, n_words, str_arr);

    for (i = 0; i < n; i++)
    {
        printf("%d ", seek_words(text, ptr_arr[i]));
    }

    printf("\n");
    // for(i = 0; i < n; i++) {
    //     printf("%s ", ptr_arr[i]);
    // }
    // show_hashmap(text);
    free(str_text);
    free(str_arr);
    free(ptr_arr);
    delete_dict(text);

    return 0;
}