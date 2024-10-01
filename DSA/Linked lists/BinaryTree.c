#include<stdlib.h>
#include<stdio.h>

struct Node {
int data;
struct Node * right, * left;
};

typedef struct Node node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}
void delete(node * tree)
{
    if (tree)
    {
        delete(tree->left);
        delete(tree->right);
        free(tree);
    }
}

void main()
{
    node *root;
    node *tmp;
   
    root = NULL;
    insert(&root, 10);
    insert(&root, 23);
    insert(&root, 15);
    insert(&root, 8);
   
    delete(root);
}
