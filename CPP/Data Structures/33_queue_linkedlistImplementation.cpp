/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int val){
        data = val;
        next = NULL;
    }
};

class queue{
    node* front;
    node* back;
    
    public:
    queue(){
        front = NULL;
        back = NULL;
    }
    
    void push(int x){
        node* n = new node(x);
        if (front == NULL){
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }
    
    void deque(){
        if (front == NULL){
            cout << "Queue Empty!" << endl;
            return;
        }
        node* todelete = front;
        front = front->next;
        
        delete todelete;
    }
    
    int peek(){
        if (front == NULL){
            cout << "Queue Empty!" << endl;
            return -1;
        }
        int ans = front->data;
        return ans;
    }
    
    bool empty(){
        if (front == NULL){
            cout << "Queue Empty!" << endl;
            return true;
        }
        return false;
    }
    
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.peek() << endl;
    q.deque();
    cout << q.peek() << endl;
    q.deque();
    cout << q.peek() << endl;
    q.deque();
    q.deque();
    q.deque();
    cout << q.peek() << endl;
    cout << "Queue Empty: " << q.empty();
    

    return 0;
}
