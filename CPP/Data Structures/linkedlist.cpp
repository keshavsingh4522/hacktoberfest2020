#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *insertend(Node *head, int data)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = new Node(data);
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = NULL;
    return head;
}
void show(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    cout << "Initial List : ";
    show(head);
    cout << endl;
    cout << "No of values to be inserted : ";
    int n;
    cin >> n;
    cout << "Enter the values : ";
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        head = insertend(head, data);
    }

    cout << "List after addition : ";
    show(head);
}
