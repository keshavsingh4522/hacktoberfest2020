#include<stdio.h>
#include<stdlib.h>
struct node
{ char brand;
int mrp;
int discount;
float sum=0,disc=0,cost;
struct node *next;
};
typedef struct node NODE;
NODE *LLnode,*head,*temp,*prev,*second;
NODE* brandname_at_front(NODE *);
NODE* brandname_at_end(NODE *);
NODE* delete_at_front(NODE *);
NODE* delete_at_end(NODE *);
void display(NODE *);


main()
{
int ch;
float sum=0,disc=0,cost;
head=NULL;

do
{
    printf("1--insert node at the front\n");
    printf("2--insert node at the end\n");
    printf("3--delete a node at the front\n");
    printf("4--delete a node at the end\n");
    printf("5--display the linked list\n");
   printf("6--close the program\n");

printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:  head=brandname_at_front(head);

                break;
case 2: head=brandname_at_end(head);

                break;
case 3:head=delete_at_front(head);

                 break;
case 4: head=delete_at_end(head);

                 break;
case 5:   display(head);
                break;
case 6: exit(0);break;
default:printf("Invalid choice\n");
                break;
}
}while(ch!=6);


}
NODE* brandname_at_front(NODE *head)
{
    LLnode=(NODE *)malloc(sizeof(NODE));
                printf("enter the data\n");
                scanf("%s%d%d",&LLnode->brand,&LLnode->mrp,&LLnode->discount);

                if(head==NULL)
                {
                    head=LLnode;
                    head->next=head;
                }
                else
                {
                  temp=head;
                  while(temp->next!=head)
            {
            temp=temp->next;
            }
                  LLnode->next=head;
                  head=LLnode;
            temp->next=head;
                }
        return(head);

}

NODE* brandname_at_end(NODE *head)
{
    LLnode=(NODE *)malloc(sizeof(NODE));
                printf("enter the details\n");
                scanf("%s%d%d",&LLnode->brand,&LLnode->mrp,&LLnode->discount);

                if(head==NULL)
                {
                    head=LLnode;
            head->next=head;
                }
                else
                {
                    temp=head;
                    while(temp->next!=head)
                    {
                        temp=temp->next;
                    }
                    temp->next=LLnode;
            LLnode->next=head;
                }
        return(head);

}

NODE* delete_at_front(NODE *head)
{
    if(head==NULL)
                {
                    printf("No cloths...cant delete a node\n");
                 }
                 else
                 {

                    if(head->next==head)
            {
            printf("cloth deleted=%d\n",head->brand,head->mrp,head->discount);
            free(head);
            head=NULL;
            }
            else
            {
            second=head->next;
            temp=head;
            while(temp->next!=head)
            {
            temp=temp->next;
            }
             printf("cloths deleted=%s\n%d\n%d\n",head->brand,head->mrp,head->discount);
            free(head);
            head=second;
            temp->next=head;
            }

                 }
                return(head);
}

NODE*  delete_at_end(NODE *head)
{
    if(head==NULL)
                {
                    printf("no cloths are here...cant delete a node\n");
                 }
                 else if(head->next==head)
                 {
                     printf("cloths deleted=%s\n%d\n%d\n",head->brand,head->mrp,head->discount);
                     free(head);
                     head=NULL;
                 }
                 else
                 {
                     temp=head;
                     while(temp->next!=head)
                     {
                         prev=temp;
                         temp=temp->next;
                     }
                     printf("cloth deleted=%s\n%d\n%d\n",temp->brand,temp->mrp,temp->discount);
                     free(temp);
                     prev->next=head;
                 }
                 return(head);
}


void display(NODE *head)
{
    if(head==NULL)
                {
                    printf("cloth list is empty\n");
                }
                else
                {
                printf("the cloths are as below\n");
                   temp=head;
                   while(temp->next!=head)
                   {
printf("Brand = %s\n",temp->brand);
printf("MRP =  Rs %.1f\n",temp->mrp);
printf("Discount = %d Percent\n\n",temp->discount);
sum=sum+(temp->mrp);
disc=disc+(((temp->mrp)*(temp->discount))/100);
temp=temp->next;
}

printf("\n");
cost=sum-disc;
printf("Sum = %.2f\n",sum);
printf("Total Amount to be Paid = %.2f\n\n",cost);
}
}

