#include <stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
struct tree_t
{
    struct tree_t *left;
    struct tree_t *right;
    int data;
};

int min_tree(struct tree_t *top) {
    if (top->left == NULL)
        if (top->right == NULL)
            return top->data;
        else
            return min(top->data, min_tree(top->right));
    else if (top->right == NULL)
        return min(top->data, min_tree(top->left));
    else
        return min(top->data, min(min_tree(top->left), min_tree(top->right)));
}

int max_tree(struct tree_t *top)
{
    if (top->left == NULL)
        if (top->right == NULL)
            return top->data;
        else
            return max(top->data, max_tree(top->right));
    else if (top->right == NULL)
        return max(top->data, max_tree(top->left));
    else
        return max(top->data, max(max_tree(top->left), max_tree(top->right)));
}

int check_is_bst(struct tree_t *top)
{
    if ((top->right == NULL) || (top->left == NULL))
        return 1;

    if (((max_tree(top->left) < top -> data) && (check_is_bst(top->left))) && (check_is_bst(top->right)))
        if (top->right != NULL)
            if (min_tree(top->right) >= top->data)
                return 1;
            else
                return 0;
        else 
            return 1;

    return 0;
}
