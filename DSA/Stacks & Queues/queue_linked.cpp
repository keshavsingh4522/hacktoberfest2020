// Implementation of queue using linked list
#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    int data;
    Queue *next;
    
    Queue(int x){
        data = x;
        next = nullptr;
    } 
};

void BuildQueue(Queue* &front, Queue* &rear) {
    front = rear = nullptr;
}

bool isEmpty(Queue* front) {
    return front == nullptr;
}

void Enqueue(Queue* &front, Queue* &rear) {
    cout << "Enter a value to enqueue: ";
    int val;
    cin >> val;
    Queue* newQueueNode = new Queue(val);
    if (rear == nullptr) {
        front = rear = newQueueNode;
    } else {
        rear->next = newQueueNode;
        rear = newQueueNode;
    }
}

void Dequeue(Queue* &front, Queue* &rear) {
    if (isEmpty(front)) {
        cout << "ERROR! Underflow" << endl;
        return;
    }
    cout << "Dequeued element: " << front->data << endl;
    Queue* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr; // Queue is empty, update rear as well
    }
    delete temp;
}

int main() {
    Queue *front, *rear;
    BuildQueue(front, rear);
    Enqueue(front, rear);
    Enqueue(front, rear);
    Enqueue(front, rear);
    Enqueue(front, rear);
    Enqueue(front, rear);

    if (rear != nullptr) {
        cout << "Rear element: " << rear->data << endl;
    } else {
        cout << "Queue is empty." << endl;
    }

    Dequeue(front, rear);
    Dequeue(front, rear);
    return 0;
}
