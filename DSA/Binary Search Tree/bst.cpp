/** A BST is a tree which have the following property - 
 * The left child is smaller than the parent node
 * The right child is larger than the parent node 
 * THERE SHOULD NOT BE ANY DUPLICATE NODES ! **/

#include <bits/stdc++.h>
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

// A utility function to do
// inorder traversal of BST
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
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

/** Delete a node -
 * There can be 3 types of node to be deleted - 
 * 1. If a node is a leaf, just clear the pointers connecting it
 * 2. If a node has only 1 child, then just store the child in a variable,
 *      then replace the node to be deleted with the stored variable
 * 3. If a node has both the childs, 
 *      First we search for the value greater than the node if it exists, then replace the
 *      current node with the value just greater than it,
 *      Or we can search for value smaller than node if it exists, and do similar **/

// returns the min value of the trees
Node *minValue(Node *root)
{
    Node *temp = root;
    while (temp && temp->left)
        temp = temp->left;

    return temp;
}

Node *deleteKey(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key < root->key)
        root->left = deleteKey(root->left, key);

    else if (key > root->key)
        root->right = deleteKey(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            // now  the node has both the children, we will find the smallest element
            // greater than the node in right substree
            Node *temp = minValue(root->right);

            // change the value of current node to the min node
            root->key = temp->key;
            root->right = deleteKey(root->right, temp->key);
            // then we delete the min value node from its position
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "Before deletion ";
    inorder(root);

    root = deleteKey(root, 20);
    cout << endl;
    inorder(root);
    root = deleteKey(root, 30);
    cout << endl;
    inorder(root);
    root = deleteKey(root, 50);
    cout << endl;
    inorder(root);
    return 0;
}