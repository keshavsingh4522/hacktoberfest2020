#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }

};

node* buildtree()
{
    int d;
    cin>>d;

    if(d==-1)
     return NULL;
    
    node* new_node= new node(d);
    new_node->left=buildtree();
    new_node->right=buildtree();
    return new_node;
}

void invert(node*root)
{
    if(root==NULL)
     return;

    invert(root->left);
    invert(root->right);

    node*temp=root;
    root->left=root->right;
    root->right=temp;

    return; 
}

int main()
{
    node* root=buildtree();
    invert(root);

}