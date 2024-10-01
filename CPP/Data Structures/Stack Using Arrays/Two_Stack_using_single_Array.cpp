#include<bits/stdc++.h>
#define size 300
using namespace std;

class stacks
{
    public:
    
    int arr[size];
    int top1,top2;
    int mid = size/2;
    
    stacks()
    {
        
        top1=-1;
        top2=mid;
    }
    
    void push1(int x)
    {
        if(top1>=mid)
        {
            cout<<"Stack 1 is under overflow condition :";
            cout<<"\n Kindly pop out some elements from the stack 1";
        }
        else
        {
            top1+=1;
            arr[top1]=x;
        }
    }
    
    void push2(int x)
    {
        if(top2>=size)
        {
            cout<<"Stack 2 is under overflow condition :";
            cout<<"\n Kindly pop out some el,ements from the stack 2";
        }
        else
        {
            top2+=1;
            arr[top2]=x;
        }
    }
    
    void pop1()
    {
        if(top1<=-1)
        {
            cout<<"The stack 1 is in underflow condition";
            cout<<"Kindly push some element in stack 1";
        }
        else
        {
            top1=top1-1;
        }
    }
    
    void pop2()
    {
        
        if(top2<=mid)
        {
            cout<<"The stack 2 is in underflow condition";
            cout<<"Kindly push some element in stack 2";
        }
        else
        {
            top2=top2-1;
        }
        
    }
    
    void top1_element()
    {
        cout<<arr[top1];
        
    }
    
    void top2_element()
    {
        cout<<arr[top2];
    }
};

int main()
{
    stacks s;
    s.push1(5);
    s.push1(6);
    s.push1(7);
    s.top1_element();
    s.pop1();
    
    cout<<endl;
    
    s.push2(8);
    s.push2(9);
    s.push2(10);
    s.top2_element();
    s.pop2();
    
}