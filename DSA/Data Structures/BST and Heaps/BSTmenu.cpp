#include<iostream>
using namespace std;
struct Node{
    int val;
    Node *left,*right;
};
Node* createNode(int elem)
{
    Node* temp = new Node();
    temp->val = elem;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
class BST{

    Node *root = NULL;
    public:
    bool search(int elem)
    {
        Node* temp = root;
        while(temp != NULL)
        {
            if(temp->val == elem)
            return true;
            else if(temp -> val < elem)
            temp = temp->right;
            else if(temp -> val >elem)
            temp = temp -> left;
        }
        return false;
    }
    
    void preorder(Node* treeRoot)
    {
        if(treeRoot == NULL)
        return ;
        cout<<treeRoot->val<<" ";
        preorder(treeRoot->left);
        preorder(treeRoot->right);
    }
    void postorder(Node* treeRoot)
    { 
        if(treeRoot == NULL)
        return ;
        postorder(treeRoot->left);
        postorder(treeRoot->right);
        cout<<treeRoot->val<<" ";

    }
    void inorder(Node* treeRoot)
    {
           if(treeRoot == NULL)
           return ;
           inorder(treeRoot->left);
           cout<<treeRoot->val<<" ";
           inorder(treeRoot->right);
    }
    void display()
    {  int choice;
        cout<<"How do you want to print the BST?\n";
        cout<<"1.Preorder\n2.PostOrder\n3.Inorder\n";
        cout<<"Enter your choice:\n";
        cin>>choice;
        switch(choice)
        {
            case 1: preorder(root);
            break;

            case 2 : postorder(root);
            break;

            case 3 : inorder(root);
            break;

            default: 
            cout<<"Wrong Choice Entered\n";
            break;
        }
    }
    void insert(int elem)
    {
        if(search(elem))
        cout<<"Elem already exists in the BST\n";
        else
        {    Node* insert = createNode(elem);
            if(root == NULL)
            {root = insert;
            return ;}

              Node* temp = root;
              while(temp!= NULL)
              {
                    if(temp->val > elem  && temp->left == NULL)
                    {
                        temp -> left = insert;
                        break;
                    }
                    else if(temp-> val < elem && temp->right == NULL)
                    {
                        temp -> right = insert;
                        break;
                    }
                    else if( temp-> val > elem)
                    temp = temp-> left ;
                    else if(temp -> val <elem)
                    temp = temp->right;
    
              }
        }
    }
    int maxDepth(Node* treeRoot,int maxi = 0)
    {
        if(treeRoot == NULL)
        return maxi;
        return max(maxDepth(treeRoot->left,maxi+1),maxDepth(treeRoot->right,maxi+1));
        
         
    }
    int minDepth(Node* treeRoot,int mini = 0)
    {
         if(treeRoot == NULL)
        return mini;
        return min(minDepth(treeRoot->left,mini+1),minDepth(treeRoot->right,mini+1));
    }
    void checkHeight()
    {
        cout<<"What do you want to find?\n1.Maxium Depth \n2. Minimum Depth\n";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1: 
            cout<<maxDepth(root)<<"\n";
            break;

            case 2:
            cout<<minDepth(root)<<"\n";
            break;

            default:
            cout<<"Wrong Choice Entred\n";
            break;
        }

    }
    void del(int elem)
    {
       if(root->left == NULL || root->right == NULL)
       {
           Node* temp = root;
           if(root->left != NULL)
           root = root->left;
           else
           root  = root->right;
           delete temp;
       }
         
         Node *temp = root,*prev = NULL;
         while(temp != NULL)
         {
       
             if(temp->val == elem)
             break;
               prev = temp;
              if(temp->val > elem)
                 temp = temp->left;
            
            else if(temp-> val <elem)
             temp = temp-> right;

           
         }
         if(temp == NULL)
         cout<<"Element not found\n";
       
         
         else if (temp->left == NULL && temp->right == NULL)
         {
             if(prev->left == temp)
             prev->left = NULL;
             else
             prev->right = NULL;
             delete temp;
         }
         else if(temp->left == NULL && temp->right != NULL)
         {
             if(prev->right == temp)
                 prev->right = temp->right;
             else
             prev->left = temp->right;

             delete temp;
         }
          else if(temp->left != NULL && temp->right == NULL)
         {
             if(prev->right == temp)
                 prev->right = temp->left;
             else
             prev->left = temp->left;

             delete temp;
         }
         else
         {
             Node* maximum = temp->right,*prev = temp;
             while(maximum->right != NULL)
             {
                 prev = maximum;
                 maximum = maximum -> right;
             }
            
             temp->val = maximum->val;
            if(maximum->left == NULL && maximum->right == NULL)
            {
               prev->right = NULL;
                delete maximum;
            }
            else
            {
                prev ->right = maximum->left;
                delete maximum;

            }
    
         }
    
    }

    
};
int main()
{  BST bst;
int choice,x;
while(true)
{
    cout<<"Menu:\n1.Insert\n2.Delete\n3.Display\n4.CheckHeight\n5.Exit\n";
    cout<<"Enter your choice\n";
    cin>>choice;
   switch(choice)
   {
       case 1:
       cout<<"Enter element to be inserted:\n";
       cin>>x;
       bst.insert(x);
       break;
       
       case 2:
       cout<<"Enter element to be deleted:\n";
       cin>>x;
       bst.del(x);
       break;

       case 3:
       bst.display();
       break;


       case 4:
       bst.checkHeight();
       break;
       
       case 5 :
       exit(1);
       break;

       default:
       cout<<"Wrong choice entered\n";
   }
}

return 0;
}




