#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    height = 1;
	}
};

Node *newNode(int val)
{
    Node *temp=new Node(val);
   
    return temp;
}

int height(Node *node)
{
    if(node==NULL)
        return 0;
    
    return node->height;
    
}

Node* rotateleft(Node *x)
{
    Node *y=x->right;
    Node *T1=y->left;
    
    y->left=x;
    x->right=T1;
    
    x->height=1+max(height(x->left),height(x->right));
    y->height=1+max(height(y->left),height(y->right));
    
    return y;
}

Node* rotateright(Node *x)
{
    Node *y=x->left;
    Node *T1=y->right;
    
    y->right=x;
    x->left=T1;
    
    x->height=1+max(height(x->left),height(x->right));
    y->height=1+max(height(y->left),height(y->right));
    
    return y;
}



Node* insertToAVL( Node* node, int data)
{
      if(!node)
      {
          return newNode(data);
      }
      if(node->data<data)
      {
          node->right=insertToAVL(node->right,data);
      }
      else if(node->data>data)
      {
          node->left=insertToAVL(node->left,data);
      }
      else
      {
          return node;
      }
      node->height=1+max(height(node->left),height(node->right));
      int balance=height(node->left)-height(node->right);
      
      if(balance>1 && node->left->data>data)
      {
         return rotateright(node);
      }
      if(balance<-1 && node->right->data<data)
      {
          return rotateleft(node);
      }
      if(balance>1 && node->left->data<data)
      {
         node->left= rotateleft(node->left);
         return rotateright(node);
      }
      if(balance<-1 && node->right->data>data)
      {
          node->right=rotateright(node->right);
          return rotateleft(node);
      }
      return node;
}
/*
Node* deleteNode(Node* root, int data)
{
    if(!root)
    {
        return NULL;
    }
    
    if(root->data>data)
    {
        root->left=deleteNode(root->left,data);
    }
    else if(root->data<data)
    {
        root->right=deleteNode(root->right,data);
    }
    else
    {
        if(root->right==NULL)
        {
            Node *temp=root->left;
            delete(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            Node *temp=root->right;
            delete(root);
            return temp;
        }
        else
        {
            Node *temp=minValueNode(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
        
        
        
    }
    if(!root)
        return NULL;
        
    root->height=1+max(height(root->left),height(root->right));
    int bal=getBalance(root);
        
    if(bal>1 && getBalance(root->left)>=0)
    {
        return rightRotate(root);
    }
    if(bal>1 && getBalance(root->left)<0)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(bal<-1 && getBalance(root->right)<=0)
    {
        return leftRotate(root);
    }
    if(bal<-1 && getBalance(root->right)>0)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
*/
void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->data << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  
  
// Driver Code 
int main()  
{  
    Node *root = NULL;  
      
    /* Constructing tree given in  
    the above figure */
    root = insertToAVL(root, 10);  
    root = insertToAVL(root, 20);  
    root = insertToAVL(root, 30);  
    root = insertToAVL(root, 40);  
    root = insertToAVL(root, 50);  
    root = insertToAVL(root, 25);  
      
    /* The constructed AVL Tree would be  
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preOrder(root);  
      
    return 0;  
}  
  
