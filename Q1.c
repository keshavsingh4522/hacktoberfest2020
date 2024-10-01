#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define size 5

int top = -1;
int array[size];

int isFull()
{
    if (top == size - 1)
        return TRUE;
    else
        return FALSE;
}

int isEmpty()
{
    if (top == -1)
        return TRUE;
    else
        return FALSE;
}

void push(int num)
{
    if (isFull())
        printf("Stack is Full...\n");
    else
    {
        top++;
        array[top] = num;
    }
}


int pop()
{
    if (isEmpty())
        printf("Stack is Empty...\n");
    else
    {
        top--;
        return array[top + 1];
    }
}

void display()
{
    if (!isEmpty())
    {
        int temp = pop();
        display();
        printf(" %d ", temp);
        push(temp);
    }
}

void insertAtBottom(int item)
{
    if (isEmpty())
    {
        push(item);
    }
    else
    {
        int temp1 = pop();
        insertAtBottom(item);

        push(temp1);
    }
}

void reverse()
{
    if (!isEmpty())
    {
        int temp = pop();
        reverse();

        insertAtBottom(temp);
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printf("Original Stack\n");
    display();
    reverse();
    printf("\nReversed Stack\n");
    display();
    return 0;
}