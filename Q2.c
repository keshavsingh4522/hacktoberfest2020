#include <stdio.h>
#include <stdlib.h>
#define size 10
int arr[size];
int top1 = -1;
int top2 = size;

void push1()
{
    if (top1 < top2 - 1)
    {
        int n;
        printf("Enter the element to be added:");
        scanf("%d", &n);

        top1++;
        arr[top1] = n;
    }
    else
    {
        printf("Stack Overflow");
    }
}

void push2()
{
    if (top1 < top2 - 1)
    {
        int n;
        printf("Enter the element to be added:");
        scanf("%d", &n);

        top2--;
        arr[top2] = n;
    }
    else
    {
        printf("Stack Overflow");
    }
}

void pop1()
{
    if (top1 >= 0)
    {
        int temp = arr[top1];
        printf("Item deleted:%d", arr[top1]);
        top1--;
    }
    else
    {
        printf("Stack Underflow");
    }
}

void pop2()
{
    if (top2 < size)
    {
        int temp = arr[top2];
        printf("Item deleted:%d", arr[top2]);
        top2++;
    }
    else
    {
        printf("Stack Underflow");
    }
}

void display()
{
    printf("\nElements present in the stack1: \n");
    for (int i = top1; i >= 0; --i)
        printf("%d\n", arr[i]);
    printf("\n\n");
    printf("\nElements present in the stack2: \n");
    for (int i = top2; i < size; i++)
        printf("%d\n", arr[i]);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nOperations performed by Stack");
        printf("\n1.Push an element\n2.Pop the top element\n3.Display current stack\n4.End");
        printf("\n\nEnter the choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push1();
            push2();
            break;
        case 2:
            pop1();
            pop2();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);

        default:
            printf("\nInvalid choice!!");
        }
    }
    return 0;
}