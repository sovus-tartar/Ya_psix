#pragma once


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