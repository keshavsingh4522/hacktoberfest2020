#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair

struct Node 
{
    int data;
    int level;
    Node *left, *right;
    Node(int val) 
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void leftView(Node *root) 
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    root -> level = 0;
    map<int, int> mp;

    int level;

    while (!q.empty()) 
    {

        Node *temp = q.front();
        level = temp -> level;


        if(mp.find(level) == mp.end())
            mp[level] = temp -> data;


        q.pop();


        if (temp -> left != NULL) 
        {
            temp -> left -> level = level + 1;
            q.push(temp -> left);
        }

        if (temp -> right != NULL) 
        {
            temp -> right -> level = level + 1;
            q.push(temp -> right);
        }
    }


    cout << "Left View of Binary Tree: " << endl;
    map<int, int> :: iterator it;

    for (it = mp.begin(); it != mp.end(); it++)
        cout << it -> second << " ";
}


int main() 
{
    map<int, Node *> m;

    int n;
    cin >> n;
    Node *root = NULL;

    for (int i = 0; i < n; i++) 
    {
        int node1, node2;
        char direction;
        cin >> node1 >> node2 >> direction;
        Node *parent, *child;
        if (m.find(node1) == m.end())
        {
            parent = new Node(node1);
            m[node1] = parent;
            if (root == NULL)
                root = parent;
        }
        else
            parent = m[node1];
        child = new Node(node2);
        if (direction == 'L')
            parent -> left = child;
        else
            parent -> right = child;
        m[node2] = child;
    }

    leftView(root);
    return 0;
}