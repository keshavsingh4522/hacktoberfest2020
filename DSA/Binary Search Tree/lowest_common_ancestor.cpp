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
/** The lowest common ancestor between two nodes n1 and n2 is defined as the lowest
 * node in T that has both n1 and n2 as descendants (where we allow a node to be a 
 * descendant of itself).
 * LCA of 2 nodes n1 and n2 lies between them, so if both of them are greater than the root,
 * we will check in the right subtree
 * if both are smaller than root, check in the left subtree
 * if one is smaller and other is greater, then we have already found the LCA **/
Node *findLCA(Node *root, int n1, int n2)
{
    while (root)
    {
        if (root->key < n1 && root->key < n2)
            root = root->right;

        else if (root->key > n1 && root->key > n2)
            root = root->left;
        else
            break;
    }

    return root;
}

int main()
{
    Node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    int n1 = 4, n2 = 8;

    cout << "LCA of " << n1 << " " << n2 << " is " << findLCA(root, n1, n2)->key << endl;
}