/** Convert a binary tree to BST without changing the tree layout **/
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

// A utility function to do
// inorder traversal of BST
vector<int> arr;
void StoreInorder(Node *root)
{
    if (root != NULL)
    {
        StoreInorder(root->left);
        // cout << root->key << " ";
        arr.push_back(root->key);
        StoreInorder(root->right);
    }
}

void putValuesInorder(Node *root, vector<int> &arr, int &ind)
{
    if (root != NULL)
    {
        putValuesInorder(root->left, arr, ind);
        root->key = arr[ind];
        ind++;
        putValuesInorder(root->right, arr, ind);
    }
}

void makeBST(Node *root)
{
    if (root == NULL)
        return;
    StoreInorder(root);
    sort(arr.begin(), arr.end());
    int i = 0;
    putValuesInorder(root, arr, i);
    arr.resize(0);
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
    cout << "Before making BST ";
    inorder(root);

    makeBST(root);

    cout << "\nAfter making BST ";
    inorder(root);
}