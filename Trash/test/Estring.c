#include <stdio.h>
#include <string.h>

char * convert (char * dst, const char * src) {
    int i, j;
    j = 0;
    for(i = 0; src[i] != '\0'; i++) {
        if ((src[i] != 'e') && (src[i] != 'y') && (src[i] != 'u') &&
            (src[i] != 'a') && (src[i] != 'o') && (src[i] != 'i') &&
            (src[i] != 'E') && (src[i] != 'Y') && (src[i] != 'U') &&
            (src[i] != 'A') && (src[i] != 'O') && (src[i] != 'I')) {
            dst[j] = src[i];
            j++;
        } 
    }
    
    dst[j] = '\0';
    return dst;
}

int main()
{
    char d[100];
    printf("_%s_\n", convert(d, "rabcEx zi"));
    // напечатает _rbcx z_
    return 0;
}