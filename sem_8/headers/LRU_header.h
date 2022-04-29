#pragma once

const int hash_pow = 100;

typedef struct hashmap_node_t
{
    struct list_node_t *list_ptr;
    struct hashmap_node_t *prev;
    struct hashmap_node_t *next;
} hashmap_node;

typedef struct hashmap_t
{
    int number_of_elements;          // powerfullness of hash
    struct hashmap_node_t *node_arr; // node_arr[hash]
} hashmap;

typedef struct cache_t
{
    int cache_size;
    int filled_nodes;
    struct list_node_t *list_ptr;
    struct hashmap_t hash_table;
} cache;

typedef struct list_node_t
{
    struct list_node_t *prev;
    struct list_node_t *next;
    int data;
} list_node;