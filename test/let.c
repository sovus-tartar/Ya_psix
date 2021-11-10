#include <stdio.h>
unsigned codeToNumber(char l1, char l2, char l3, char l4){

unsigned s1, s2, s3, s4;
unsigned s;

s1 = (unsigned)l1 + 1 - 'A';
s2 = (unsigned)l2 + 1 - 'A';
s3 = (unsigned)l3 + 1 - 'A';
s4 = (unsigned)l4 + 1 - 'A';

s = s4 + 100 * (s3 + 100 * (s2 + 100 * s1));

printf("%u, %u, %u, %u\n%u\n", s1, s2, s3, s4, s);

return s;

}

int main(){
char l1, l2, l3 ,l4;
unsigned long long number;
scanf("%c%c%c%c", &l1, &l2, &l3, &l4 );

printf("%08u\n", codeToNumber(l1, l2, l3, l4));
}