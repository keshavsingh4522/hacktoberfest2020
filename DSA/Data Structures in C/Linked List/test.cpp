#include <bits/stdc++.h>
#include "conio.h"
using namespace std;
struct node
{
    int val;
    node *next=nullptr;
};
node * start=nullptr;
void inserte(int n)
{
    node *noodie=new node;
    noodie->val=n;
    if(start==nullptr)
    {
        start=noodie;
        noodie->next=noodie;
        return;
    }
    node * temp=new node;

    temp=start;
    while(temp->next!=start)
    {
        temp=temp->next;
    }
    temp->next=noodie;
    noodie->next=start;
}
void display()
{
    node *temp=new node;
    temp=start;
    while(temp->next!=start)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<temp->val<<" "<<(temp->next)->val;
}
int main()
{
    cout<<"enter 1. insert 2.display";
    int wish,n;
    char ch;
    do{
        node a;
        cin>>wish;
        switch(wish)
        {
            case 1 : cout<<"enter the element to be inserted";
                cin>>n;
                inserte(n);
                break;
            case 2 : display();
                break;
        }
        cout<<"enter y to continue";
        ch=getch();
    }while(ch=='y');

    return 0;
}