#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node_t {
    struct node_t *left;
    struct node_t *right;
    int data;
} node;

void to_read(int n, int *arr)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

int arr_seek(int *arr, int n, int num)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == num)
            return i;
    }
    return -1;
}

node *bin_tree_build(int nodes, int *in, int *pre)
{
    node *root;
    int in_pos, pre_pos;

    root = calloc(1, sizeof(node));
    assert(root != NULL);
    root->data = *pre;

    if (((in_pos = arr_seek(in, nodes, pre[0])) != -1) && (in_pos != 0))
    { //left node
        root->left = bin_tree_build(in_pos, in, pre + 1);
    }
    else
        root->left = NULL;

    if (((nodes > in_pos + 1) && (in_pos != -1)) && (in_pos != nodes - 1)) //right node
        root->right = bin_tree_build(nodes - in_pos - 1, in + in_pos + 1, pre + in_pos + 1);
    else
        root->right = NULL;

    printf("Created node: %d addr: %p, L: %p, R: %p\n", root -> data, root, root -> left, root -> right);

    return root;
}

int tree_topology_build(node *top, int *arr_topology, int *arr_data, int i)
{

    arr_topology[0] = 1;
    arr_data[0] = top->data;

    if ((top->right == NULL) && (top -> left == NULL)) {
        return 1;
    }
    
    if (top->left != NULL)
    {   i = 1;
        //printf("Node: %d, left: %p, i = %d\n", top -> data , top -> left, i);
        i = tree_topology_build(top->left, arr_topology + 1, arr_data + 1, i) + i;
    }

    if (top->right != NULL)
    {
        //printf("Node: %d, right: %p, i = %d\n", top -> data , top -> right, i);
        i = i + tree_topology_build(top->right, arr_topology + 2 * i, arr_data + i, 1);
        
    }

    
    return i;
}

void tree_topology_print(node *top, int n)
{
    int *arr_topology;
    int *arr_data;
    int i;
    arr_topology = calloc(2 * n, sizeof(int));
    arr_data = calloc(n, sizeof(int));

    tree_topology_build(top, arr_topology, arr_data, 1);

    printf("%d ", n);
    printf("\n");
    for (i = 0; i < 2 * n; i++)
    {
        printf("%d ", arr_topology[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr_data[i]);
    }

    printf("\n");
}

int main(void)
{
    int n, *preorder, *inorder, i;
    node *top;
    scanf("%d", &n);

    preorder = calloc(n, sizeof(int));
    inorder = calloc(n, sizeof(int));

    to_read(n, preorder);
    to_read(n, inorder);

    top = bin_tree_build(n, inorder, preorder);
    tree_topology_print(top, n);
    return 0;
}