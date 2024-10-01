#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node *root=NULL;

node *create(int data)
{
	node *temp=new node();
	temp->data=data;
	//for new node created both left and right links are set as null
	temp->left=temp->right=NULL;
	return temp;
}

node *insert(node *root,int data)
{
	//if tree is empty then we will just create new node and insert data
	if(root==NULL)
	{
		root=create(data);
	}
	//if data value is less than root value then recursively insert to left
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	//if data value is more than root value then recursively insert to right
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}

void levelorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	//create a queue that will store the pointer to node to reach back to the nodes while traversing
	queue<node*>q;
	//when we only have root node address then we will push that into queue
	q.push(root);
	while(!q.empty())
	{
		//while there is atleast one node adress saved inside the queue we can use the loop
		node *temp=q.front();
		cout<<temp->data<<" ";
		if(temp->left!=NULL)
		{
			q.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			q.push(temp->right);
		}
		//removing the element from front
		q.pop();
	}
}

node *findmin(node *root)
{
	if(root==NULL)
	{
		return NULL;
	}
	node *temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}

node *del(node *root,int data)
{
	if(root==NULL)
	{
		return root;
	}
	else if(data<root->data)
	{
		root->left=del(root->left,data);
	}
	else if(data>root->data)
	{
		root->right=del(root->right,data);
	}
	else
	{
		//case 1->no child of root node
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
		}
		//case 2->1 child of root node (right child)
		else if(root->left==NULL)
		{
			node *temp=root;
			//iterate to right subtree as left is null  
			root=root->right;
			delete temp;
		}
		//case 3->1 child of root node (left child)
		else if(root->right==NULL)
		{
			node *temp=root;
			//iterate to left subtree as right is null (1 child)
			root=root->left;
			delete temp;
		}
		//case 4->2 children of root node
		else
		{
			node *temp=findmin(root->right);
			root->data=temp->data;
			root->right=del(root->right,temp->data);
		}
		return root;
	}
}

int main()
{
	root=insert(root,12);
	root=insert(root,5);
	root=insert(root,15);
	root=insert(root,3);
	root=insert(root,7);
	root=insert(root,13);
	root=insert(root,17);
	root=insert(root,1);
	root=insert(root,9);
	root=insert(root,14);
	root=insert(root,20);
	root=insert(root,8);
	root=insert(root,11);
	root=insert(root,18);
	
	cout<<"Before Deleting Level Order Traversal:";
	levelorder(root);
	cout<<endl;
	
	del(root,15);
	
	cout<<"After Deleting Level Order Traversal:";
	levelorder(root);
	cout<<endl;
}
