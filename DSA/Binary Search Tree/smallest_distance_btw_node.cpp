#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Node
{
public:
    Node(){};
    int key;
    Node *left, *right;
};

// A utility function to create a new BST node
Node *newNode(int item)
{
    Node *temp = new Node();
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to
insert a new node with given key in
 * BST */
Node *insert(Node *node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

/** We will use the idea of LCA for finding it,
 * if the two nodes are greater than root, check the right
 * else check the left
 * if one is greater and other is less, then we have found the LCA,
 * now the smallest distance between them is the sum of distance from the LCA
 * to both of the nodes **/
int distanceFromRoot(Node *root, int x)
{
    if (root->key == x)
        return 0;
    else if (x > root->key)
        return 1 + distanceFromRoot(root->right, x);
    return 1 + distanceFromRoot(root->left, x);
}

// we are assuming that n1 < n2
int distanceBtwNodes(Node *root, int n1, int n2)
{
    if (root == NULL)
        return 0;

    if (n1 > root->key && n2 > root->key)
        return distanceBtwNodes(root->right, n1, n2);

    if (n1 < root->key && n2 < root->key)
        return distanceBtwNodes(root->left, n1, n2);

    else if (n1 <= root->key && n2 >= root->key) // we found the LCA
        return distanceFromRoot(root, n1) + distanceFromRoot(root, n2);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 35);

    int a = 35, b = 5;
    if (a > b)
        swap(a, b);
    cout << "Min distance is " << distanceBtwNodes(root, a, b);
}