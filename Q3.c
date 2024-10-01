#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define size 6

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
    }
}

void display()
{
    if (isEmpty())
    {
        printf("\nThe expression is balanced");
    }
    if (!isEmpty())
    {
        printf("The expression is unbalanced");
    }
}

int main()
{
    int a[6] = {'(', '{', '[', ']', '}', ')'};
    for (int i = 0; i < 6; i++)
    {

        if (a[i] == '(' || a[i] == '{' || a[i] == '[')
        {
            push(a[i]);
        }
        if (a[i] == ')' || a[i] == '}' || a[i] == ']')
        {
            pop();
        }
    }
    display();
    return 0;
}