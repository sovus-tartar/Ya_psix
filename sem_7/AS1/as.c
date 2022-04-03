#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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

enum reg_t reg_code(char *str)
{
    char c;
    c = str[0];

    switch (c)
    {
    case 'A':
        return A;
    case 'B':
        return B;
    case 'C':
        return C;
    case 'D':
        return D;
    };

    return WRONG_RG;
}

int op_code(enum mnemonic_t mnemonic)
{
    char reg1[2], reg2[2];
    enum reg_t Reg1, Reg2;

    if (scanf("%s %s", reg1, reg2) == 0)
        return -1;

    if (((Reg1 = reg_code(reg1)) == WRONG_RG) ||
        ((Reg2 = reg_code(reg2)) == WRONG_RG))
        return -1;

    return ((int)mnemonic + (((int)Reg1) << 2) + (int)Reg2);
}

int in_out_code(enum mnemonic_t mnemonic)
{
    enum reg_t Reg1;
    char reg1[2];

    if (scanf("%s", reg1) == 0)
        return -1;

    if ((Reg1 = reg_code(reg1)) == WRONG_RG)
        return -1;

    return ((int)mnemonic + (int)Reg1);
}

int to_code()
{
    char reg1, reg2;
    enum reg_t Reg1, Reg2;
    int i, num;
    enum mnemonic_t mnemonic;
    char mnem[5];

    if (scanf("%s", mnem) == EOF)
        return -2;

    mnemonic = WRONG_MN;

    if (!strncmp("MOVI", mnem, 4))
        mnemonic = MOVI;

    if (!strncmp("ADD", mnem, 3))
        mnemonic = ADD;

    if (!strncmp("SUB", mnem, 3))
        mnemonic = SUB;

    if (!strncmp("MUL", mnem, 3))
        mnemonic = MUL;

    if (!strncmp("DIV", mnem, 3))
        mnemonic = DIV;

    if (!strncmp("IN", mnem, 2))
        mnemonic = IN;

    if (!strncmp("OUT", mnem, 3))
        mnemonic = OUT;

    if (mnemonic == WRONG_MN)
        return -1;

    switch (mnemonic)
    {
    case MOVI:
        if (scanf("%d", &num) == 0)
            return -1;
        return num;
    case ADD:
        return op_code(mnemonic);
    case SUB:
        return op_code(mnemonic);
    case MUL:
        return op_code(mnemonic);
    case DIV:
        return op_code(mnemonic);
    case IN:
        return in_out_code(mnemonic);
    case OUT:
        return in_out_code(mnemonic);
    };

    return -1;
}

int to_read()
{
    int code;

    while ((code = to_code()) != -2)
    {
        if (code == -1)
        {
            printf("ERROR");
            exit(0);
        }

        printf("0x%x ", code);
    }

    return 0;
}

int main()
{

    to_read();

    return 0;
}