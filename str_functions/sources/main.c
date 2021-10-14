#include "../headers/functions.h"

#include <stdio.h>

//TODO strcpy
//TODO strncpy
//TODO strcat
//TODO strncat
//TODO fgets
//TODO strdup
//TODO getline


int main() {
    //unit_test_strchr();
    //unit_test_strlen();
    char string_1[20] = "";
    char string_2[20] = "";

    scanf("%s", string_1);

    strcpy_f(string_2, string_1);

    printf("%s %d", string_1, strlen_f(string_2));
}

