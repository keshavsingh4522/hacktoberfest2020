#include<iostream>
#include<stack> // Using STL stack 
using namespace std;
struct Node 
{
    int val;
    Node *left,*right;
}*root =  NULL;
Node *createNode(int elem)
{
    Node *temp = new Node();
    temp->val = elem;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void insert(int elem)
{
     Node *insert = createNode(elem);
     if(root == NULL)
      root = insert;
     else
     {
         Node* temp = root;
         while(temp != NULL)
         {
             if(temp->val > elem && temp->left == NULL)
             {
                 temp->left = insert;
                 break;
             }
             else if(temp->val < elem && temp->right == NULL)
             {
                 temp->right = insert;
                 break;
             }
             else if(temp->val > elem )
             temp = temp->left;
             else if(temp->val <elem)
             temp = temp->right;
             else
             {
                 cout<<"Element already Exists.\n";
                 break;
             }
         }
     }

}
int main()
{
// Sample BST
  insert( 50); 
  insert( 30); 
  insert( 20); 
  insert( 40); 
  insert( 70); 
  insert( 60); 
  insert( 80); 
  

  cout<<"Inorder Traversal Using Stack: ";
  stack<Node* > tr;
Node *temp = root;
  while(temp != NULL || !tr.empty())
  {
      while(temp != NULL)
      {
          tr.push(temp);
          temp = temp->left;
      }
      temp = tr.top();
      tr.pop();
      cout<<temp->val<<" ";
      temp = temp->right;
  }

}