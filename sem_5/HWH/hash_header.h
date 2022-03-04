typedef struct bucket_t
{
    char *ptr; //ptr to string
    struct bucket_t *next; //
} bucket;

typedef struct hashmap_t 
{
    bucket *top;
        
};

void clear_buffer();
int hashmap_seek(bucket *table, char *target);
void show_hashmap(bucket *table);
int count_hash(char *str);
bucket *strings_to_hashmap(int n, char *str);
void delete_hashmap(bucket *table);
bucket *hashmap_add(bucket *top, char *str);