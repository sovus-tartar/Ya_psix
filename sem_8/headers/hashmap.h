#pragma once

const int hash_pow = 50;    // powerfullness of hash

typedef struct hashmap_node_t
{
    void *data;
    struct hashmap_node_t *prev;
    struct hashmap_node_t *next;
} hashmap_node;

typedef struct hashmap_arr_t 
{
    hashmap_node * node_ptr;
    //int collisions;
} hashmap_arr;

typedef struct hashmap_t
{
    int number_of_elements;          // powerfullness of hash
    hashmap_arr * node_arr; // node_arr[hash]
} hashmap;

int hash_count(int key);
hashmap * hashmap_create();
void hashmap_delete(hashmap * H);
hashmap_node * hashmap_create_node(void * data);
void hashmap_add(hashmap_node * node, int hash);
void hashmap_remove(hashmap * H);
void hashmap_delete_node(hashmap * H, int hash, void * data)
