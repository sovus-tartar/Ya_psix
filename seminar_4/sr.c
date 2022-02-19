#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n_word, n_str;
    char *word, *str, *temp, *word1;
    int c, i, count;
    count = 0;
    scanf("%d", &n_word);
    word = calloc(n_word + 1, sizeof(char));
    word1 = calloc(n_word + 1, sizeof(char));
    scanf("%s", word);

    scanf("%d", &n_str);
    str = calloc(n_str + 1, sizeof(char));
    getchar();

    for (i = 0; i < n_str; i++)
    {
        scanf("%c", &str[i]);
    }

    str[n_str] = '\0';

    for (i = 0; i < n_word; i++)
    {
        word1[i] = word[n_word - i - 1];
    }

    temp = str;
    while ((temp != strstr(temp, word)) && ((temp = strstr(temp, word)) != NULL))
    {
        for (i = 0; i < n_word; i++)
        {
            temp[i] = word1[i];
        }
    }

    printf("%s", str);

    free(word);
    free(str);
    free(word1);
}