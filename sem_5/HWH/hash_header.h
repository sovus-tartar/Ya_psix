typedef struct word_t
{
    char *ptr;
    int hash;
    struct word_t *next;
} hashmap;

int count_hash(char *str);

hashmap *read_dict(int n, char *str);
void delete_dict(hashmap *top);
void seek_words(hashmap *word, hashmap *text);
void clear_buffer();