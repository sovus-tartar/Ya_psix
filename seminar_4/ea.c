#include <stdio.h>
#include <string.h>

void minus_plus(char * str) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') 
            str[i] = '+';
    }
}

void reverse_out(int argc, char **argv) {
    int i;

    for (i = argc - 1; i > 0; i--) {
        printf("%s ", argv[i]);
    }
    printf("\n");
}

void normal_out(int argc, char **argv) {
    int i;

    for (i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }

    printf("\n");
}


int main(int argc, char **argv) {
    int i, k;
    k = 0;
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-r")) {
            k = 1;
        }
        minus_plus(argv[i]);
    }
    if (k == 1) 
        reverse_out(argc, argv);
    else
        normal_out(argc, argv); 


}