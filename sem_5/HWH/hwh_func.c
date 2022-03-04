#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "hwh_header.h"


void clear_buffer()
{
    char c;
    while (c = getchar() != '\n');
}

char **read_words(int n, int n_words, char* str_arr)
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

    //for(i = 0; i < n; i++)
    //    printf("%s %p\n", ptr_arr[i], ptr_arr + i - 1);
    assert(j == n);
    return ptr_arr;
}

