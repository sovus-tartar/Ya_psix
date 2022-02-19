#include <stdio.h>
#include <stdlib.h>
struct node_t {
    struct node_t * next;
    int cont;
}

int is_odd(int n) {
    return n % 2;
}

void next_node(struct node_t **curr_ptr, int t) {
    *curr_ptr -> cont = t;
    *curr_ptr -> next = calloc(1, sizeof(struct node_t));
    assert(*curr_ptr -> next);
    *curr_ptr = *curr_ptr -> next;
}

struct node_t * read_list (FILE *f) {
    struct node_t * top_even, * top_odd, * curr_ptr_even, * curr_ptr_odd;
    int temp; 


    top_even = calloc(1, sizeof(struct node_t)); 
    top_odd = calloc(1, sizeof(struct node_t));

    assert(top_even);
    assert(top_odd);
    
    curr_ptr_even = top_even;
    curr_ptr_odd = top_odd;

    while(fscanf(f, "%d", &temp) != EOF) {
        if (is_odd(temp)) {
            next_node(curr_ptr_odd, temp);
        } else {
            next_node(curr_ptr_even, temp);
        }
    }

    curr_ptr_even -> next = top_odd;

    return top_even;
}

int main(int argc, char ** argv) {
    FILE * f;
    struct node_t top, curr;
    f = fopen(argv[1], "r");

    top = read_list(f);
    
    

    fclose(f);

}