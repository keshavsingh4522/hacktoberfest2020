
#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int x) {
            data = x;
            next = NULL;
        }
};
Node* head = NULL;

void insert( Node* node) {
    if (head == NULL) {
        head = node;
    } else {
        Node* temp = head;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void display(Node* head_ptr) {
    Node* temp = head_ptr;
    while (temp!=NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* head2 = NULL;
void reverseList() {
    Node* temp = head;
    while(temp!=NULL) {
        // 11 12 13 14
        // temp->data=11 new_node ka data ab
        // 14 13 12 11
        Node* new_node = new Node(temp->data);
        if(head2 == NULL) {
            head2 = new_node;
        } else {
            new_node->next = head2; 
            head2 = new_node;
            // temp=temp->next;
        }
            temp=temp->next;
    }
    cout << "reversed list:\n";
    display(head2);
}
int main() {
    insert(new Node(11));
    insert(new Node(12));
    insert(new Node(13));
    insert(new Node(14));
    insert(new Node(15));
    display(head);
    reverseList();
    return 0;
}