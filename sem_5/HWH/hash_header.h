typedef struct hashmap_t
{
    char *ptr;
    struct hashmap_t *next;
} hashmap;

int hashmap_seek(hashmap *table, char *target);
void show_hashmap(hashmap *table);
int count_hash(char *str);
hashmap *strings_to_hashmap(int n, char *str);
void delete_hashmap(hashmap *table);
hashmap *hashmap_add(hashmap *top, char *str);