// Given postorder and inorder traversals ,construct the BST.
// Only postorder traversal is required (my observation).
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
    int data ;
    Node *left,*right;
}*root = NULL;
Node* createNewNode(int elem)
{
    Node *temp = new Node();
    temp->data = elem;
    temp->left = temp->right = NULL;
    return temp;
}
void insertusingpostorder(int elem)
{
  Node* insert =  createNewNode(elem);
    if (root == NULL)
    root = insert;
    else
    {
        Node *temp = root;
        while(true)
        {
           if(temp->data > elem and temp->left == NULL)
           {temp->left = insert;
           break;}
           else if(temp->data < elem and temp->right == NULL)
           {temp->right = insert;
           break;}

           else if(temp->data > elem)
           temp = temp->left;

           else if(temp->data  < elem)
           temp = temp->right;
           
        }
    }

}
void inorder(Node *treeRoot)
{
    if(treeRoot == NULL)
    return ;
    inorder(treeRoot->left);
    cout<<treeRoot->data<<" ";
    inorder(treeRoot->right);
}
int main()
{
   int n;
   cout<<"Enter number of elements in BST: \n";
   cin>>n;
   vector<int> x(n);
   cout<<"Enter elements in Postorder fashion: \n";
   for(int i = 0;i<n;i++)
   cin>>x[i];

    reverse(x.begin(),x.end());
   for(int elem :x)
   insertusingpostorder(elem);



    cout<<"Inorder fashion of the constructed tree : \n";
   inorder(root);

}