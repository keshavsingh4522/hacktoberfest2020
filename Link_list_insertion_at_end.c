#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node *new;
new insertATend(struct Node *head, int data)
{
    new newNode;
    newNode = (new)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;

    new p = head;
    if (p==NULL)
    {
        p=newNode;
        
    }
    else
    {
        
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = newNode;
    }
    
    
    
    return head;
};

new traverse(new head)
{   new ptr;
     ptr=head;

    while (ptr!= NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->link;
    }
};
int main()
{
    new head;
    head = (new)malloc(sizeof(struct Node));
    head = NULL;
    int data;
    printf("ENter the data\n");
    scanf("%d",&data);
    
    //   head->data=33;
    //   head->link=NULL;

    insertATend(head, data);
    printf("ENter the data\n");
    scanf("%d",&data);
    insertATend(head, data);
    printf("ENter the data\n");
    scanf("%d",&data);
    insertATend(head, data);
    
    traverse(head);

    return 0;
}