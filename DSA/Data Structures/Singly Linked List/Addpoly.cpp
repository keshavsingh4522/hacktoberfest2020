#include<bits/stdc++.h> 
using namespace std;
struct Node{
    int coeff,power;
    Node *next;
};
Node* create_Node(int coeff1,int power1)
{
        Node* ptr = new Node();
        ptr->coeff = coeff1;
        ptr->power = power1;
        ptr->next = NULL;
        return ptr;  
}
void insertatbeg(Node** head,Node *insert)
{
        if(head==NULL)
        *head = insert;
        else
        {
            insert->next = *head;
            *head = insert;

        }
}
void printpoly(Node *head)
{
        Node *ptr = head;
        while(ptr!=NULL)
        {
            cout<<ptr->coeff<<"x^"<<ptr->power<<"+";
            ptr = ptr->next;
        }

}
Node* addpoly(Node* head1,Node* head2,Node** ans)
{
           Node*ptr1 = head1,*ptr2 = head2;
           *ans = NULL;
           while(ptr1!=NULL && ptr2!=NULL)
           {
               if(ptr1->power>ptr2->power)
               {
                Node* ptr = create_Node(ptr1->coeff,ptr1->power);
                insertatbeg(&*ans,ptr);
                ptr1 = ptr1->next;
               }
               else if(ptr1->power<ptr2->power)
               {
                Node* ptr = create_Node(ptr2->coeff,ptr2->power);
                insertatbeg(&*ans,ptr);
                ptr2 = ptr2->next;
               }
               else
               {
                    Node* ptr = create_Node(ptr2->coeff+ptr1->coeff,ptr2->power);
                insertatbeg(&*ans,ptr);
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
               }
           }

            while(ptr1!=NULL )
           {
               
            Node* ptr = create_Node(ptr1->coeff,ptr1->power);
                insertatbeg(&*ans,ptr);
               
           }
            while(ptr2!=NULL )
           {
               
            Node* ptr = create_Node(ptr2->coeff,ptr2->power);
                insertatbeg(&*ans,ptr);
               
           }
           return head1;
}
int main()
{
Node *poly1=NULL,*poly2=NULL,*ans = NULL;
int coeff,power;

//polynomial 1 
for(int i=1;i<=3;i++)
{  coeff=power=i;
    Node* ptr = create_Node(coeff,power);
    insertatbeg(&poly1,ptr);
}

cout<<"First Polynomial:  ";
printpoly(poly1);

//Polynomial 2
for(int i=1;i<=5;i++)
{  coeff=power=i;
    Node* ptr = create_Node(coeff,power);
    insertatbeg(&poly2,ptr);
}

cout<<"\nSecond Polynomial:  ";
printpoly(poly2);
addpoly(poly1,poly2,&ans);
cout<<"\nSum is:  ";
printpoly(ans);
return 0;
}
