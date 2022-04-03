#include <stdio.h>
#include <limits.h>

struct tree_t
{
    struct tree_t *left;
    struct tree_t *right;
    int data;
};

int foo(struct tree_t *curr, int n_min, int n_max)
{

    if ((curr->left != NULL) && (curr->right != NULL) &&
        (curr->left->data > n_min) && (curr->left->data < curr->data) &&
        (curr->right->data > curr->data) && (curr->right->data < n_max))
        return ((foo(curr->left, n_min, curr->data) && foo(curr->right, curr->data, n_max)));
    else
    {

        if ((curr->left == NULL) && (curr->right->data > curr->data) && (curr->right->data < n_max))
            return foo(curr->right, curr->data, INT_MAX);
        if ((curr->right == NULL) && (curr->left->data > n_min) && (curr->left->data < curr->data))
            return foo(curr->left, 0, curr->data);

        return 1;
    }

    return 0;
}

int check_is_bst(struct tree_t *top)
{
    return foo(top, 0, INT_MAX);
}
