#include<bits/stdc++.h>
using namespace std;

struct TNode{
 int data;
 struct TNode *left,*right;
 TNode(int data)
 {
  this->data = data;
  left = right = NULL;
 }
};

typedef struct TNode* tptr;

void printBoundaryLeft(tptr root)
{
 if(root)
 {
  if(root->left)
  {
   cout<<root->data<<" ";
   printBoundaryLeft(root->left);
  }
  else if(root->right)
  {
   cout<<root->data<<" ";
   printBoundaryLeft(root->right);
  }
 }
}
void printBoundaryRight(tptr root)
{
 if(root)
 {
  if(root->right)
  {
   printBoundaryRight(root->right);
   cout<<root->data<<" ";
  }
  else if(root->left)
  {
   printBoundaryRight(root->left);
   cout<<root->data<<" ";
  }
 }
}
void printBoundaryLeaves(tptr root)
{
 if(root)
 {
  printBoundaryLeaves(root->left);
  if( root->left==NULL && root->right==NULL)
   cout<<root->data<<" ";
  printBoundaryLeaves(root->right);
 } 
}
void printBoundary(tptr root)
{
 if(root)
 {
  cout<<root->data<<" ";
  // Left Boundary
  printBoundaryLeft(root->left);

  // Leaves
  printBoundaryLeaves(root->left);
  printBoundaryLeaves(root->right);
  
  // Right Boundary
  printBoundaryRight(root->right);
 }
}
int main()
{
 tptr root = new TNode(1);
 root->left = new TNode(2);
 root->right = new TNode(3);
 root->left->left = new TNode(4);
 root->left->right = new TNode(5);
 printBoundary(root);
 return 0;
}
