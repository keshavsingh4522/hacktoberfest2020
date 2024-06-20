#include <iostream>
#include <cmath>

using namespace std;
class node{
public:
int data;
node* next;
node* prev;
};

void create(node* h,int n){
  node*a,*head=h;
  int x;
  h=a;
  while(n-->=1){
    a=new node();
    head=a;
    x= srand()%100;
    a->data=x;
    a->next=NULL;
    head=a->next;
  }
}

void printfte(node* h){
  cout<<"Doubly linked list traversed from front to end: ";
  node*a=h;
  do{
    cout<<a->data<<",";
    a=a->next;
  }while(a->next!=NULL);
}
int main(){

  int n,x;
  cout<<"enter any number";
  cin>>n;
  node* head=NULL;
  create(head,n);
  printfte(head);
   return 0; 
}