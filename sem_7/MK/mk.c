#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned char reg_A = 0, reg_B = 0, reg_C = 0, reg_D = 0;


enum reg_t
{
    WRONG_RG = -1,
    A,
    B,
    C,
    D
};

enum mnemonic_t
{
    WRONG_MN = -1,
    MOVI = 0,
    ADD = 0x80,
    SUB = 0x90,
    MUL = 0xA0,
    DIV = 0xB0,
    IN = 0xC0,
    OUT = 0xC4
};

int is_movi(unsigned char num) 
{
    return !(num >> 7);
}

int is_inout(enum mnemonic_t mnem, unsigned char num) 
{
    num = num & 0xFC;
    //printf("%hhu %hhu\n", num, mnem);
    return ((enum mnemonic_t)num == mnem);
}


enum mnemonic_t mnem(unsigned char num) {
    
    if (is_movi(num))
        return MOVI;
    
    if (is_inout(IN, num))
        return IN;
    if (is_inout(OUT, num))
        return OUT;

    return (enum mnemonic_t)(num & 0xF0);
}

unsigned char * get_ptr(enum mnemonic_t m) {
    switch(m) {
        case A:
            return &reg_A;
        case B:
            return &reg_B;
        case C:
            return &reg_C;
        case D:
            return &reg_D;
    }

    return NULL;
}

void movi(unsigned char num) {
    reg_D = num;
}

void add(unsigned char* el1, unsigned char* el2) {
    *el1 = (*el1 + *el2) % 256;
}

void sub(unsigned char* el1, unsigned char* el2) {
    *el1 = (*el1 - *el2) % 256;
}

void mul(unsigned char* el1, unsigned char* el2) {
    *el1 = ((*el1) * (*el2)) % 256;
}

void divide(unsigned char* el1, unsigned char* el2) {
    *el1 = ((*el1) / (*el2)) % 256;
}

void in(unsigned char* el) {
    scanf("%hhu", el);
}

void out(unsigned char* el) {
    printf("%hhu\n", *el);
}

void pull(unsigned char num) {
    enum mnemonic_t mnemonic;
    unsigned char * ptr1, *ptr2;
    mnemonic = mnem(num);
    ptr1 = get_ptr(((enum reg_t)num & 0x0F) >> 2);
    ptr2 = get_ptr((enum reg_t)num & 0x3);

    switch(mnemonic) {
        case MOVI:
            movi(num);
            break;
        case IN:
            in(ptr2);
            break;
        case OUT:
            out(ptr2);
            break;
        case ADD:
            add(ptr1, ptr2);
            break;
        case MUL:
            mul(ptr1, ptr2);
            break;
        case DIV:
            divide(ptr1, ptr2);
            break;
        case SUB:
            sub(ptr1, ptr2);
            break;
        default:
            printf("ERROR");
            exit(0);
    }
}    

char * skip_to_space(char * str) {
    int i;
    i = 0;

    while(!isspace(str[i])) {
        if (str[i] == '\0') 
            return NULL;
        i = i + 1;

    }
    
    return str + i + 1;
}

int main(int argc, char * argv[]) {
    unsigned char c;
    int len;
    char * str;

    len = strlen(argv[1]);
    str = calloc(len + 1, sizeof(char));
    strcpy(str, argv[1]);

    while((str != NULL) && (sscanf(str, "%hhx", &c))) {
        pull(c);
        str = skip_to_space(str);
    }
    
    free(str);
    return 0;
}