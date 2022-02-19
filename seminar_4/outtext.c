#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv) {
    FILE *f;
    int c;
    if (argc > 2) abort();

    f = fopen(argv[1], "r");
    if (f == 0) 
        perror("Error opening file");

    while((c = fgetc(f)) != EOF) {
        printf("%c", c);
    }
    printf("\n");
    fclose(f);
}
