#include <stdio.h>

struct pos {
    int letter;
    int number;
};

int bee(struct pos p, struct pos * restricted) {
    int a[3];
    int i, j, count, avaliable;
    struct pos x[3];
    //printf("bla");
    if ((p.letter == 'h') && (p.number == 8)) return 1;
    count = 0; 
    avaliable = 0;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            if (i*i + j*j == 0) break;
            x[count].letter = p.letter + i;
            x[count].number =  p.number + j;
            if ((x[count].letter > 'h') || (x[count].number > 8)) {
                a[count] = 0;
            } else {
                avaliable+=bee(x[count], restricted) ;
            }
            count++;
        }
    }
    printf("%c%d:%d %c%d:%d %c%d:%d \n", x[0].letter, x[0].number, a[0],
                                x[1].letter, x[1].number, a[1],
                                x[2].letter, x[2].number, a[2]);
    return (avaliable);
}

int foo (struct pos p, struct pos horse) {
    struct pos no_access[9];
    int i, j, k, count;

    no_access[0] = horse;
    
    count = 1;
    for(i = 1; i < 3; i++) {
        int delta_x, delta_y;
        if (i == 1) {
                    delta_x = 2;
                    delta_y = 1;
                } else {
                    delta_x = 1;
                    delta_y = 2;
                }; //направление хода
        for(j = 1; j < 3; j++) { //верх или низ
        if (j == 2) {
            delta_y = -delta_y;
        }
            for (k = 1; k < 3; k++) { //лево или право
                if (k == 2) {
                    delta_x = -delta_x;
                }
                no_access[count].letter = horse.letter + delta_x;
                no_access[count].number = horse.number + delta_y;
                if ((no_access[count].letter == 'h') && (no_access[count].number == 0)) return 0; 
                count++;
            }
        }
    }
    
    return bee(p, no_access);

}

int main() {
    struct pos horse, p;
    p.letter = 'a';
    p.number = 1;

    scanf("%c%d", &horse.letter, &horse.number);
    //foo(p, horse);
    printf("%d", foo(p, horse));
}