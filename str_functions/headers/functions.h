///sring.h functions realisation
///all functions names are ("function_name"_f) to avoid conflicts


char* strchr_f(char* string, int symbol);
void unit_test_strchr(void);
struct strchr_test {
    char string[16];
    int letter;
    char expect_string[16];
};

int strlen_f(const char* string);
void unit_test_strlen(void);
struct strlen_test{
    char string[100];
    int expected_characters;
};

char* strcpy_f(char* destination_string, const char* string);

