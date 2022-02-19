#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct word_t
{
    char *ptr;
    int hash;
    struct word_t *next;
} _word;

int const q = 10; // hash("abc") == (q^2 * 'a' + q^1 * 'b' + q^0 * 'c') % p
int const p = 10000;

int count_hash(char *str)
{ 
    int n, i, h;

    n = strlen(str);
    h = 0;

    for (i = 0; i < n; i++)
        h += ((q ^ (n - i)) * str[i]) % p;

    return h;
}

void clear_buffer()
{
    char c;
    while (c = getchar() != '\n')
        ;
}

_word *read_dict(int n, char *str)
{
    int i, j;
    _word *top, *curr;
    clear_buffer();

    top = calloc(1, sizeof(_word));
    assert(top != NULL);
    top->ptr = str;
    curr = top;

    for (i = 0; i < n; i++)
    { //read to array
        str[i] = getchar();

        if (str[i] == ' ')
        {
            _word *temp;

            str[i] = '\0';

            temp = calloc(1, sizeof(_word));
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

void delete_dict(_word *top)
{
    _word *curr, *temp;
    curr = top;
    while (curr != NULL)
    {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
}

void seek_words(_word *word, _word *text)
{
    assert(word != NULL);
    assert(text != NULL);

    while (word != NULL)
    {
        int target, count;
        _word *curr;
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

int main()
{
    _word *text, *words;
    char *str_text, *str_words;
    int n_text, n, n_words;

    scanf("%d", &n);
    scanf("%d", &n_text);

    str_text = calloc(n_text + 1, sizeof(char));
    assert(str_text != NULL);
    text = read_dict(n_text, str_text);

    scanf("%d", &n_words);

    str_words = calloc(n_words + 1, sizeof(char));
    assert(str_words != NULL);
    words = read_dict(n_words, str_words);

    seek_words(words, text);

    printf("\n");
    free(str_text);
    delete_dict(text);
    delete_dict(words);

    return 0;
}