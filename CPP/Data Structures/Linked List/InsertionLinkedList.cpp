#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal_Linkedlist(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *inertion_Begin(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node *insert_AtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    // apn ko index -1 krna hai kyuki agr 3rd position pe insert krna hai toh
    // 2 to 3 link tod ke naya insert krke naya wala 3rd index pe ayega
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *insertAt_End(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }

    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct Node *insert_AfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // reserve memory in heap;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 21;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = NULL;

    traversal_Linkedlist(head);
    // head = inertion_Begin(head, 121);
    printf("\n");
    // // traversal_Linkedlist(head);1
    // printf("\n");
    // head = insert_AtIndex(head, 101, 1);
    // head = insertAt_End(head, 38);
    head = insert_AfterNode(head, second, 3);
    traversal_Linkedlist(head);

    return 0;
}
