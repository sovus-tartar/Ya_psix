#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "hwh_header.h"

int main()
{
    hashmap *text;
    char *str_text, **ptr_arr, *str_arr;
    int n_text, n, n_words, i;
    
    scanf("%d", &n);
    scanf("%d", &n_text);

    str_text = calloc(n_text + 1, sizeof(char));
    assert(str_text != NULL);
    text = strings_to_hashmap(n_text, str_text);

    scanf("%d", &n_words);
    str_arr = calloc(n_words + 1, sizeof(char));

    ptr_arr = read_words(n, n_words, str_arr);

    for(i = 0; i < n; i++) {
        printf("%d ", hashmap_seek(text, ptr_arr[i]));
    }

    

    printf("\n");
    //for(i = 0; i < n; i++) {
    //    printf("%s ", ptr_arr[i]);
    //}
    //show_hashmap(text);
    free(str_text);
    free(str_arr);
    free(ptr_arr);
    delete_hashmap(text);
    

    return 0;
}