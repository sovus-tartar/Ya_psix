#include <stdio.h> //for NULL

#include "../headers/functions.h"

char *strchr_f(char* string, int symbol){
    int condition = 0;

    for(int count = 0; string[count] != '\0'; count++){
        if (string[count] == symbol) {
            condition = 1;
            return &string[count];
        }
    }

    if (condition == 0) return NULL;
}

int strlen_f(const char* string){
    int stop_cond = 0;
    int count = 0;
    for(count = 0; stop_cond == 0; count++){
        if (string[count] == '\0') stop_cond = 1;
        printf("%c", string[count]);
    }

    return count - 1;
}

char* strcpy_f(char* destination_string, const char* string){
    for(int count = 0; count < (strlen_f(string) + 1); count++)
        destination_string[count] = string[count];
    return destination_string;
}
