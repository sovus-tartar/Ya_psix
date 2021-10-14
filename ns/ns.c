#include <stdio.h>

void ns_translate(unsigned x, unsigned y); 

int main(){
    unsigned x, y;
    scanf("%u %u", &x, &y);
    ns_translate(x,y);
}
void ns_translate(unsigned x, unsigned y){

    if (x < y) {printf("%u", x);}
    else {ns_translate(x / y, y); printf("%u", x % y);}
}




