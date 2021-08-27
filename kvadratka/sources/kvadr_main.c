#include "../include/kvadr_head.h"

int main(void) {

    printf("Square equations solver\n"
           "ver. alpha 1.0 by Sovus_tartar, 2021\n");

    user_interface();

#ifdef DEBUG
    unit_test();                //For debugging purposes
#endif

    program_exit();

    return 0;
}
