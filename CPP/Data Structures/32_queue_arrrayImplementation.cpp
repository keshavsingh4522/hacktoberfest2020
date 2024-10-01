 /******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

#define n 100

class queue{
    int* arr;
    int front;
    int back;
    
    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }
    
    void push(int x){
        if (back == n-1){
            cout << "Queue full!" << endl;
            return;
        }
        back ++;
        arr[back] = x;
        cout << x << " has entered the queue!" << endl;
        
        if(front == -1){
            front ++;
        }
    }
    
    void deque(){
        if (front == -1 || front >back){
            cout << "Queue Empty!" << endl;
            return;
        }
        front ++;
        cout <<"Deque! " << arr[front] << " is now at front!" << endl;
    }
    
    void peek(){
        if (front == -1 || front >back){
            cout << "Queue Empty!" << endl;
            return;
        }
        cout << arr[front] << " is at front of the queue!" << endl;
    }
    
    bool empty(){
        if (front == -1 || front >back){
            cout << "Queue Empty!" << endl;
            return true;
        }
        else{
            return false;
        }
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
    q.peek();
    q.deque();
    q.peek();
    q.deque();
    q.deque();
    q.deque();
    q.deque();
    cout << "Queue Empty: " << q.empty();

    return 0;
}
