#include "../headers/hashmap.h"
#include <stdlib.h>
int hash_count(int key)
{
    key += ~(key << 16);
    key ^= (key >> 5);
    key += (key << 3);
    key ^= (key >> 13);
    key += ~(key << 9);
    key ^= (key >> 17);

#ifdef DEBUG
    printf("Hash for number: %d calculated: %d\n", n, key % hash_pow);
#endif

    return (key % hash_pow);
}

hashmap *hashmap_create()
{
    hashmap *temp;

    temp = calloc(1, sizeof(hashmap));
    assert(temp);

    temp->number_of_elements = hash_pow;
    temp->node_arr = calloc(hash_pow, sizeof(hashmap_arr *));
    assert(temp->node_arr);
#ifdef DEBUG
    printf("Hashmap created, hash_pow = %d\n", hash_pow);
#endif
    return temp;
}

void hashmap_delete(hashmap *H)
{
    int i;

    for(i = 0; i < H->number_of_elements; i++) 
    {
        hashmap_node * temp;
        
        temp = (H->node_arr + i)->node_ptr;

        while(temp) 
        {
            hashmap_node * next_nd;
            next_nd = temp->next;
            free(temp);
            temp = next_nd;
        }
    }

    free(H->node_arr);
    free(H);
#ifdef DEBUG
    printf("Hashmap deleted\n");
#endif
}

hashmap_node *hashmap_create_node(void *data)
{
    hashmap_node *temp;

    assert(data);

    temp = calloc(1, sizeof(hashmap_node));
    temp->data = data;
#ifdef DEBUG
    printf("Hashmap node(%p) created with data(%p)\n", temp, data);
#endif
    return temp;
}

void hashmap_add_node(hashmap *H, hashmap_node *node, int hash)
{
    hashmap_arr *temp;

    assert(H);
    assert(node);

    temp = H->node_arr + hash;

    if (temp->node_ptr)
    {
        hashmap_node *temp_node;
        temp_node = temp->node_ptr;

        while (temp_node->next)
        {
            temp_node = temp_node->next;
        }

        temp_node->next = node;
        node->prev = temp_node;
    }
    else
    {
        temp->node_ptr = node;
    }

#ifdef DEBUG
    printf("Hashmap: node(%p) added, hash = %d\n", node, hash);
#endif
}

void *hashmap_get_node(hashmap *H, int hash, void *data)
{
    hashmap_node *temp;
    assert(H);
    assert(data);
    temp = (H->node_arr + hash)->node_ptr;

    while (temp)
    {
        if ((temp->data) == data) {
#ifdef DEBUG
            printf("Hashmap: got node (%p) with hash: %d, data: %p\n", temp, hash, data);
#endif
            return temp;
        }
        temp = temp->next;
    }



    return NULL;
}

void hashmap_delete_node(hashmap *H, int hash, void *data)
{
    hashmap_node *temp, *prev_nd, *next_nd;

    assert(H);
    assert(data);

    temp = hashmap_get_node(H, hash, data);

    if (temp == NULL)
    {
        printf("No data (%p) to delete with hash %d in hashmap (%p)\n", data, hash, H);
        abort();
    }

    prev_nd = temp->prev;
    next_nd = temp->next;

    if (next_nd)
    {
        if (prev_nd)
        {
            prev_nd->next = next_nd;
            next_nd->prev = prev_nd;
            free(temp);
        }
        else
        {
            (H->node_arr + hash)->node_ptr = next_nd;
            free(temp);
        }
    }
    else
    {
        if (prev_nd)
        {
            prev_nd->next = NULL;
            free(temp);
        }
        else
        {
            (H->node_arr + hash)->node_ptr = NULL;
            free(temp);
        }
    }

#ifdef DEBUG
    printf("Hashmap: node(%p) deleted, hash = %d, data: %p\n", temp, hash, data);
#endif
}
