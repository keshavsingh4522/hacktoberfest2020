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

/** We will traverse the left subtree and check if the kth element is present, else
 * we go to the right subtree **/
Node *kthSmallest(Node *root, int &k)
{
    if (root == NULL)
        return NULL;

    Node *left = kthSmallest(root->left, k);

    if (left) // we keep on going to left is there are nodes present
        return left;

    k--;
    if (k == 0) // here we found the kth smallest
        return root;

    return kthSmallest(root->right, k);
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

    int k = 3;
    cout << k << "rd Smallest element is " << kthSmallest(root, k)->key << endl;
}