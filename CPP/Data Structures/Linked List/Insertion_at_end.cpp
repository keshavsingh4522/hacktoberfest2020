#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
void add_at_end(struct node *head, int data)
{
    struct node *temp, *ptr;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    while (ptr->link != NULL)
    {
        cout << ptr->data << " ";
    }
}
int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 20;
    head->link = NULL;
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 18;
    current->link = NULL;
    head->link = current;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 11;
    current->link = NULL;
    head->link->link = current;
    add_at_end(head, 19);
    // cout<<head->data<<" "<<head->link;
    return 0;
}