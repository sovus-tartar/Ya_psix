#include <stdio.h>

#include "../headers/functions.h"

void unit_test_strchr(void){


    struct strchr_test test_strings[] = {
            "molkek", 'k', "kek",
            "How are you", 'a', "are you",
            "niceMonkey", 'M', "Monkey"
    };

    for(int count = 0; count <= sizeof test_strings / sizeof test_strings[0] - 1 ; count++){

        if (*strchr_f(test_strings[count].string, test_strings[count].letter) == *test_strings[count].expect_string){
            printf("string = \"%s\" letter = \"%c\" PASS\n", test_strings[count].string, test_strings[count].letter);
        } else {
            printf("string = \"%s\" letter = \"%c\" expected_string = \"%s\" but got \"%s\"\n",
                   test_strings[count].string, test_strings[count].letter, test_strings[count].expect_string,
                   strchr_f(test_strings[count].string, test_strings[count].letter));
        }
    }
}

void unit_test_strlen(void){

    struct strlen_test test_strings[] = {
            "one", 3,
            "three", 5,
            "lolkekcheburek", 14
    };

    for(int count = 0; count < (sizeof test_strings / sizeof test_strings[0]); count++){
        int function_output = 0;
        if ((function_output = strlen_f(test_strings[count].string)) == test_strings[count].expected_characters)
            printf("string: \"%s\", characters = %d PASS\n",
                   test_strings[count].string, test_strings[count].expected_characters);
        else printf("string: \"%s\", expected number: %d, but got: %d FAILED",
                    test_strings[count].string, test_strings[count].expected_characters, function_output);
    }
}