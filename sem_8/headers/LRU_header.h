#pragma once
#include "../headers/list.h"
#include "../headers/hashmap.h"

typedef struct cache_t
{
    int cache_size;
    int filled_nodes;
    struct list_node_t * list_ptr;
    struct hashmap_t * hash_table;
} cache;
