#include <stdio.h>
#include <stdlib.h>
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

char reg_symb(unsigned char num) {
    //printf("%hhx\n", num);
    switch(num) {
        case A:
            return 'A';
        case B:
            return 'B';
        case C:
            return 'C';
        case D:
            return 'D';
    }

    return -1;
}

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

void print_movi(char num) {
    printf("MOVI %hhu\n", num);
}

void print_op(enum mnemonic_t mnemonic, unsigned char num) {
    
    switch (mnemonic) {
        case ADD:
            printf("ADD ");
            break;
        case SUB:
            printf("SUB ");
            break;
        case MUL:
            printf("MUL ");
            break;
        case DIV:
            printf("DIV ");
            break;
        default:
            printf("ERROR");
            exit(0);
    }

    printf("%c, %c\n", reg_symb((num & 0xC) >> 2), reg_symb(num & 0x3));
}

void print_inout(enum mnemonic_t mnemonic, unsigned char num) {

    switch(mnemonic) {
        case IN:
            printf("IN ");
            break;
        case OUT:
            printf("OUT ");
            break;
        default:
            printf("ERROR");
            exit(0);
    }

    printf("%c\n", reg_symb(num & 0x3));
}

void print(unsigned char num) {
    enum mnemonic_t mnemonic;

    mnemonic = mnem(num);

    switch(mnemonic) {
        case MOVI:
            print_movi(num);
            break;
        case IN:
            print_inout(IN, num);
            break;
        case OUT:
            print_inout(OUT, num);
            break;
        default:
            print_op(mnemonic, num);
    }
}    


int main() {
    unsigned char c;

    while(scanf("%hhx", &c)) {
        print(c);
    }

    return 0;
}