#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "hash_header.h"

//TODO: хэш таблица должна стать таблицей
int main()
{
    hashmap *text, *words;
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