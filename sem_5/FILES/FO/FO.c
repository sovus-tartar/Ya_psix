#include <stdio.h>

void display_file(FILE * fptr);

int main() {
    FILE *fptr;

    fptr = fopen("input.txt", "r");
    if (fptr == NULL) 
        perror("Error opening file: ");

    display_file(fptr);

    fclose(fptr);

    return 0;
}

void display_file(FILE * fptr) {
    char c;
    c = 0;

    while((c = getc(fptr)) != EOF) {
        printf("%c", c);
        
    }

    printf("\n");

}