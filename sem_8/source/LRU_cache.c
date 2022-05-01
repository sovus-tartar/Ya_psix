#include "../headers/LRU_header.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


/*
    To see all debug information compile in gcc with -DDEBUG tag
*/

#ifdef DEBUG
void hashmap_dump(hashmap *H) {
    int i, num;
    num = H->number_of_elements;

    printf("START OF HASHMAP DUMP~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    for(i = 0; i < num; i++) {
        hashmap_node *curr, *temp;
        int j;
        curr = (H->node_arr + i) -> node_ptr;
        printf("HASH = %d:\n", i);
    
        for(j = 0; j < (H->node_arr + i)->collisions; j++) {
            printf("%d--", ((list_node*) (curr -> data)) -> data);

        }
        printf("\n");
    }

    printf("END OF HASHMAP DUMP~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}

#endif

list_node * hashmap_get_data(hashmap * H, int hash, int data) {
    hashmap_node * curr;
    list_node * temp;
    int n, i;
    curr = (H->node_arr + hash)->node_ptr;
    n = (H->node_arr + hash) -> collisions;

    for(i = 0; i < n; i++) {
        
        temp = curr -> data;

        if (temp -> data) {
#ifdef DEBUG
        printf("Hashmap: found data %p (%d) with hash %d\n", temp, data, hash);
#endif
        }
        curr = curr -> next;
    }
#ifdef DEBUG
        printf("Hashmap: can't get data %p (%d) with hash %d\n", temp, data, hash);
#endif

    return NULL;
}

cache * init_cache(int n)
{
    cache* temp;
    temp = calloc(1, sizeof(cache));
    temp->cache_size = n;
    temp->list_ptr = create_list(n);
    temp->filled_nodes = 0;
    temp->hash_table = hashmap_create();
#ifdef DEBUG
    printf("Cache initialized, hashmap: %p, list: %p, size: %d\n", temp->hash_table, temp->list_ptr, n);
#endif
    return temp;
}

void cache_add_elem(cache *C, int data, int hash_data)
{
    hashmap_node *temp;
    list_node *node;
    assert(C);
    assert(C->filled_nodes < C->cache_size);
    C->filled_nodes += 1;

    node = list_create_node(data);

    C->list_ptr = list_put_to_top(C->list_ptr, node);

    temp = hashmap_create_node(node);
    hashmap_add_node(C->hash_table, temp, hash_data);

#ifdef DEBUG
    printf("Cache: element with data: %d (hash = %d) added\n", data, hash_data);
#endif    
}

void cache_remove_last(cache *C)
{
    int data, hash;
    hashmap_node *temp;
    list_node *last;

    assert(C);

    last = list_get_last(C->list_ptr);
    data = last->data;
    hash = hash_count(data);

#ifdef DEBUG
    printf("Cache: removed last element (%p) with data: %d (hash = %d)\n", last, data, hash);
#endif
    if (C->filled_nodes == C->cache_size)
    {

        C->filled_nodes -= 1;
        hashmap_delete_node(C->hash_table, hash, last);
    }

    list_remove_elem(last);
}


list_node *cache_try_get(cache *C, int data)
{
    int hash_data;
    list_node *temp;
    hash_data = hash_count(data);
    assert(C);
#ifdef DEBUG
    printf("Cache: requested element with data: %d (hash = %d)\n", data, hash_data);
#endif
    temp = hashmap_get_data(C->hash_table, hash_data, data);

    if (temp)
    {
#ifdef DEBUG
        printf("Cache: request element with data: %d (hash = %d) SUCCESS\n", data, hash_data);
#endif
        C->list_ptr = list_move_to_top(C->list_ptr, temp);
    }
    else
    {
        list_node *last;
#ifdef DEBUG
        printf("Cache: request element with data: %d (hash = %d) FAILED\n", data, hash_data);
#endif
        last = list_get_last(C->list_ptr);
        cache_remove_last(C);
        cache_add_elem(C, data, hash_data);
    }
#ifdef DEBUG
    hashmap_dump(C->hash_table);
#endif
    return temp;
}

void cache_show(cache *C)
{
    int n, i;
    list_node *curr;

    n = C->cache_size;
    curr = C->list_ptr;

    for (i = 0; i < n; i++)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}



int main()
{
    int m, tries, i, success;
    cache* C;

    assert(scanf("%d", &m));
    C = init_cache(m);

    assert(scanf("%d", &tries));
    success = 0;
    for (i = 0; i < tries; i++)
    {
        int num;
        assert(scanf("%d", &num));

#ifdef DEBUG
        printf("--------------------------------------------------------------------------------------------------------------------------------------\nENTERED VALUE: %d\n", num);
        if (cache_try_get(C, num)) {
            printf("SUCCESS to get %d\n", num);
            success+=1;
        }
        else {
            printf("FAILED to get %d\n", num);
        }
        cache_show(C);
        
#endif

#ifndef DEBUG
    if (cache_try_get(C, num))
        success += 1;
#endif
    }
    printf("%d\n", success);

}