#include "../headers/hashmap.h"
#
int hash_count(int key) {
    
    key += ~(key << 16);
    key ^=  (key >>  5);
    key +=  (key <<  3);
    key ^=  (key >> 13);
    key += ~(key <<  9);
    key ^=  (key >> 17);


#ifdef DEBUG
    printf("Hash for number: %d calculated: %d\n", n, key % hash_pow);
#endif

    return (key % hash_pow);
}

hashmap * hashmap_create() {
    hashmap * temp;
    
    temp = calloc(1, sizeof(hashmap));
    assert(temp);

    temp -> number_of_elements = hash_pow;
    temp -> node_arr = calloc(hash_pow, sizeof(hashmap_node *));
    assert(temp -> node_arr);

    return temp;

}

void hashmap_delete(hashmap * H) {
    
}

hashmap_node * hashmap_create_node(void * data) {
    
    hashmap_node * temp;

    temp = calloc(1, sizeof(hashmap_node));

    temp->data = data;
    
    return temp;
}

void hashmap_add_node(hashmap_node * node, int hash) {

}

void hashmap_delete_node(int hash, hashmap_node_t * ) {

}

void hashmap_remove(hashmap * H) {

}

