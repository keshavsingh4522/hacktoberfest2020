//implement binary tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
struct node *makenode(int x)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
int BSTinsert(int key)
{
    struct node *x,*y,*z;
    x=root;
    y=makenode(key);
    while(x!=NULL)
    {
        z=x;
        if(x->data<key)
            x=x->right;
        else
            x=x->left;
    }
    if(key<z->data)
        z->left=y;
    else
        z->right=y;
}
int BSTmin(struct node *s)
{
    while(s->left!=NULL)
    {
        s=s->left;
    }
    return s->data;
}
int BSTmax(struct node *s)
{
    while(s->right!=NULL)
    {
        s=s->right;
    }
    return s->data;
}
struct node *BSTsearch(int key)
{
    struct node *t;
    t=root;
    while(t!=NULL)
    {
      if(t->data==key)
        return t;
      else
      {
        if(key<t->data)
            t=t->left;
        else
            t=t->right;
      }
    }
    return NULL;
}
int InOrdertraversal(struct node *t)
{
    if(t!=NULL)
    {
        InOrdertraversal(t->left);
        printf(" %d",t->data);
        InOrdertraversal(t->right);
    }
}
void main()
{
    int A[]={13,45,23,67,56,93,72,18,35};
    root=NULL;
    root=makenode(A[0]);
    for(int i=1;i<9;i++)
    {
        BSTinsert(A[i]);
    }
    printf("Elements in the binary search tree ->");
    InOrdertraversal(root);
    int p=BSTmax(root);
    printf("\nMax Element->%d",p);
    p=BSTmin(root);
    printf("\nMin Element->%d",p);
    struct node *r=BSTsearch(56);
    printf("\nSearched element is present at %u",r);
    printf("\nSearched element->%d",r->data);
}
