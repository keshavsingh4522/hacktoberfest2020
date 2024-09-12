#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int head;
    int data;
};

Node *newNode(int key)
{
    Node *node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}

void topview(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    map<int, int> m;
    int head = 0;
    root->head = head;

    q.push(root);

    cout << "The top view of the tree is : \n";

    while (q.size())
    {
        head = root->head;


        if (m.count(head) == 0)
            m[head] = root->data;
        if (root->left)
        {
            root->left->head = head - 1;
            q.push(root->left);
        }
        if (root->right)
        {
            root->right->head = head + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }

    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->second << " ";
    }
}


int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary Tree\n";
    topview(root);
    return 0;
}