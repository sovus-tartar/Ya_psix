#include <stdio.h>
#include <stdlib.h>

struct node_t {
  struct node_t *next;
  int data;
};


int loop_len(struct node_t *top) {
    struct node_t *rabbit, *turtle;
    int t, r;
    t = 0;
    r = 0;
    rabbit = top;
    turtle = top;
    while(rabbit != NULL) {
        if ((rabbit = rabbit -> next) != NULL)
            if((rabbit = rabbit -> next) != NULL);
            else 
                return 0;
        else 
            return 0;
        t = t + 1;
        r = (r + 2) % t;
        turtle = turtle -> next;

        if (turtle == rabbit) 
            return t - r;
    }

    return 0;
}

int main() {
    struct node_t *top, *curr;
    int i;

    top = calloc(1, sizeof(struct node_t));
    top -> data = 0;
    curr = top;

    for(i = 1; i < 100000; i++){
        curr -> next = calloc(1, sizeof(struct node_t));
        curr = curr -> next;
        curr -> data = i;
    }

    curr -> next = top;

    
    

    printf("%d", list_is_a_loop(top));

    
}