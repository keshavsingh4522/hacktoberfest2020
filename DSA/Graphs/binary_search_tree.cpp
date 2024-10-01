#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, char data)
{
    if(root==NULL)
        {
            root=(struct node *)(malloc(sizeof(struct node)));
            root->left= root->right = NULL;
            root->data=data;
            return root;
        }
        else if( data < root->data )
            root->left=insert(root->left,data);
        else if( data > root->data )
            root->right=insert(root->right,data);
        return(root);
}

  void search(struct node *root, char key)
{
    struct node *temp = (struct node*)(malloc(sizeof(struct node*)));
    temp= root;
    while (temp!=NULL)
        {
            if (temp->data==key)
            {
                cout<<"\nfound";
                return;
            }
            if (key < temp->data)
                temp=temp->left;
            else
                temp= temp->right;
        }
        cout<<"\nnot found";
}

int main()
{
    struct node *root=NULL;
    int n,i;
    string a;
    char key;
    root=NULL;
    cout<<"\nEnter the string:";
    cin>>a;
    cout<<"\nEnter character to be searched:";
    cin>>key;
    n=a.length();
    char arr[n + 1];
    strcpy(arr, a.c_str());
    for(i=0;i<n;i++)
        root=insert(root,arr[i]);
    search(root,key);
    return 0;
}
