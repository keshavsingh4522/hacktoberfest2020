#include <iostream>
using namespace std;

template<class T>
class node{
public:
    T data;
    node *next;
};
template<class T>
class linkedlist{
private:
    node<T> *first{};
public:
    linkedlist(){first=nullptr;}
    linkedlist(T A[],int n);
    ~linkedlist();

    void display();
    void Insert(int index,T x );
    T delete1(int index);
    int len();
};
template<class T>
linkedlist::linkedlist(T A[], int n) {
    node<T> *last,*t;
    first=new node<T>;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new node<T>;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

linkedlist::~linkedlist() {
    node *p=first;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}

void linkedlist::display() {
    node *p=first;
    while(p){
        cout<<p->data;
        p=p->next;
    }
    cout<<endl;
}
template<class T>
void linkedlist::Insert(int index, T x) {
    if(index<0||index >len()){
        return ;
    }
    node *p=first;
    node *t;
    t=new node<T>;
    t->data=x;
    t->next=NULL;
    if(index==0){
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}
template<class T>
T linkedlist::delete1(int index)
{
    node *p=first,*q=NULL;
    int x;
    if(index<0||index >len()){
        return 0;
    }
    if(index==1){
        first=first->next;
        x=p->data;
        delete p;
    }
    else{
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }q->next=p->next;
        x=p->data;
        delete p;
    }
}
int linkedlist::len() {
    node *p=first;
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

int main() {
    int a[5]={1,2,3,4,5};
    linkedlist<int> l(a,5);
    l.display();
    cout<<l.len()<<endl;
    l.delete1(5);
    l.display();
    l.Insert(4,5);
    l.display();
    return 0;
}
