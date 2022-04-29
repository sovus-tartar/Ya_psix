#include "../headers/LRU_header.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


/*
    To see all debug information compile in gcc with -DDEBUG tag
*/
int calc_hash(int n)
{
    int hash, i;
    hash = 0;
    i = 1;

    while (n > 0)
    {
        hash += (n % 10) % hash_pow;
        
        n /= 10;
    }

#ifdef DEBUG
    printf("Hash for number: %d calculated: %d\n", n, hash);
#endif

    return hash;
}

hashmap hashmap_create(int n)
{
    hashmap A;

    A.number_of_elements = n;
    A.node_arr = calloc(n, sizeof(hashmap_node));
    assert(A.node_arr);
#ifdef DEBUG
    printf("hashmap for %d nodes generated\n", n);
#endif
    return A;
}

void hashmap_delete(hashmap H)
{
    int n, i;
    n = H.number_of_elements;

    for (i = 0; i < n; i++)
    {
        free(H.node_arr + i);
    }
#ifdef DEBUG
    printf("Hashmap deleted\n");
#endif
}

void hashmap_add_elem(hashmap *H, hashmap_node *node, int hash)
{
    hashmap_node *curr;

    curr = H->node_arr + hash;

    if (curr->list_ptr == NULL)
    {
        curr->list_ptr = node->list_ptr;
        free(node);
    }
    else
    {
        while (curr->next)
        {
            curr = curr->next;
        }

        curr->next = node;
        node->prev = curr;
    }

#ifdef DEBUG
    printf("Hashmap: node (%p) put to hashmap (hash = %d)\n", node, hash);
#endif
}

void hashmap_remove_elem(hashmap_node *node)
{
    hashmap_node *prev_el, *next_el;

    prev_el = node->prev;
    next_el = node->next;
    if (next_el)
    {
        if (prev_el)
        {
            prev_el->next = next_el;
            next_el->prev = prev_el;
            free(node);
        }
        else
        { // no prev el
            node->next = next_el->next;
            node->list_ptr = next_el->list_ptr;
            node->prev = NULL;
            free(next_el);
        }
    }
    else
    {
        if (prev_el)
        {
            prev_el->next = NULL;
            free(node);
        }
        else
        {
            node->list_ptr = NULL;
        }
    }

#ifdef DEBUG
    printf("Hashmap: removed node (%p)\n", node);
#endif

}

hashmap_node *hashmap_create_node(list_node *data)
{
    hashmap_node *temp;

    temp = calloc(1, sizeof(hashmap_node *));
    assert(temp);
    temp->list_ptr = data;

#ifdef DEBUG
    printf("Hashmap: node created (%p), data: %d (%p)\n", temp, data->data);
#endif

    return temp;
}

hashmap_node *hashmap_get_node(hashmap *H, int hash_data, int data)
{
    hashmap_node *curr;
    int i;

    curr = H->node_arr + hash_data;

    while (curr)
    {
        if (curr->list_ptr->data == data)
#ifdef DEBUG
    printf("Hashmap: found node (%p) for hash: %d with value: %d\n", curr, hash_data, data);
#endif

            return curr;

        curr = curr->next;
    }

#ifdef DEBUG
    printf("Hashmap: node not found for hash: %d with value: %d\n", curr, hash_data, data);
#endif

    return NULL;
}

list_node *hashmap_get_data(hashmap *H, int hash_data, int data)
{
    hashmap_node *curr;
    int i;

    curr = H->node_arr + hash_data;

    while (curr)
    {
        if (curr->list_ptr)
        {
            if (curr->list_ptr->data == data)
#ifdef DEBUG
                printf("Hashmap: found node (%p) for hash: %d with value: %d\n", curr, hash_data, data);
#endif
                return curr->list_ptr;
        }

        curr = curr->next;
    }
#ifdef DEBUG
    printf("Hashmap: node not found for hash: %d with value: %d\n", curr, hash_data, data);
#endif
    return NULL;
}

list_node *create_list(int n)
{
    int i;
    list_node *top, *curr;

    top = calloc(1, sizeof(list_node));
    assert(top);
    curr = top;

    for (i = 1; i < n; i++)
    {
        list_node *temp;

        temp = calloc(1, sizeof(list_node));
        assert(temp);
        temp->prev = curr;
        curr->next = temp;
        curr = temp;
    }

    curr->next = top;
    top->prev = curr;
#ifdef DEBUG
    printf("List created\n");
#endif
    return top;
}

void list_remove_elem(list_node *node)
{
    list_node *prev_el, *next_el;

    prev_el = node->prev;
    next_el = node->next;

    prev_el->next = next_el;
    next_el->prev = prev_el;
#ifdef DEBUG
    printf("List: node (%p) with val: %d removed\n", node, node->data);
#endif
    free(node);
}

list_node *list_get_last(list_node *top)
{
#ifdef DEBUG
    printf("List: got last element (%p)\n", top->prev);
#endif
    return top->prev;
}

list_node *list_create_node(int data)
{
    list_node *temp;
    temp = calloc(1, sizeof(list_node *));
    assert(temp);
    temp->data = data;
#ifdef DEBUG
    printf("List: node (%p) with data: %d created\n", temp, data);
#endif
    return temp;
}

cache init_cache(int n)
{
    cache temp;

    temp.cache_size = n;
    temp.list_ptr = create_list(n);
    temp.filled_nodes = 0;
    temp.hash_table = hashmap_create(hash_pow);
#ifdef DEBUG
    printf("Cache initialized, hashmap: %p, list: %p\n", &temp.hash_table, temp.list_ptr);
#endif
    return temp;
}

list_node *list_put_to_top(list_node *top, list_node *node)
{
    assert(top);
    assert(node);

    node->next = top;
    node->prev = top->prev;
    top->prev->next = node;
    top->prev = node;

#ifdef DEBUG
    printf("List: node (%p) with data: %d put to top\n", node, node->data);
#endif


    return node;
}

list_node *list_move_to_top(list_node *top, list_node *node)
{
    list_node *prev_el, *next_el;

    assert(top);
    assert(node);

    if (top == node) {
#ifdef DEBUG
        printf("List: node (%p) is already on the top\n", node);
#endif
        return node;
    }
    prev_el = node->prev;
    next_el = node->next;

    prev_el->next = next_el;
    next_el->prev = prev_el;

#ifdef DEBUG
    printf("List: node (%p) moved to top\n", node);
#endif

    return list_put_to_top(top, node);
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
    hashmap_add_elem(&(C->hash_table), temp, hash_data);

#ifdef DEBUG
    printf("Cache: element with data: %d (hash = %d) added\n", data, hash_data);
#endif    
}

void cache_remove_last(cache *C)
{
    int data, hash_data;
    hashmap_node *temp;
    list_node *last;

    assert(C);

    last = list_get_last(C->list_ptr);
    data = last->data;
    hash_data = calc_hash(data);

#ifdef DEBUG
    printf("Cache: removed last element (%p) with data: %d (hash = %d)\n", last, data, hash_data);
#endif
    if (C->filled_nodes == C->cache_size)
    {

        C->filled_nodes -= 1;
        temp = hashmap_get_node(&(C->hash_table), hash_data, data);
        hashmap_remove_elem(temp);
    }

    list_remove_elem(last);
}

list_node *cache_try_get(cache *C, int data)
{
    int hash_data;
    list_node *temp;
    hash_data = calc_hash(data);
#ifdef DEBUG
    printf("Cache: requested element with data: %d (hash = %d)\n", data, hash_data);
#endif
    temp = hashmap_get_data(&(C->hash_table), hash_data, data);

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
        printf("Cache: requeste element with data: %d (hash = %d) FAILED\n", data, hash_data);
#endif
        last = list_get_last(C->list_ptr);
        cache_remove_last(C);
        cache_add_elem(C, data, hash_data);
    }

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
    cache C;

    assert(scanf("%d", &m));
    C = init_cache(m);

    assert(scanf("%d", &tries));
    success = 0;
    for (i = 0; i < tries; i++)
    {
        int num;
        assert(scanf("%d", &num));

#ifdef DEBUG
        if (cache_try_get(&C, num))
            printf("ENTERED VALUE: %d\nSUCCESS\n", num);
        else
            printf("ENTERED VALUE: %d\nFAILED\n", num);
        cache_show(&C);
        
#endif


    if (cache_try_get(&C, num))
        success += 1;

    }


    printf("%d\n", success);

}