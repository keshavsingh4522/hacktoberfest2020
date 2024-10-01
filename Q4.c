#include <stdio.h>
#include <ctype.h>

#define MAXSTACK 100
#define SIZE 100

int stack[MAXSTACK];
int top = -1;

void push(int item)
{

    if (top >= MAXSTACK - 1)
    {
        printf("Stack Overflow");
        return;
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

int pop()
{
    int item;
    if (top < 0)
    {
        printf("Stack Underflow");
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return item;
    }
}

void evaluate(char postfix[])
{

    int i;
    char ch;
    int val;
    int A, B;

    for (i = 0; postfix[i] != ')'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {

            A = pop();
            B = pop();

            switch (ch)
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;

            case '^':
                val = B ^ A;
            }

            push(val);
        }
    }
    printf(" \n Result: %d \n", pop());
}

int main()
{

    int i;
    char postfix[SIZE];
    printf(" \nEnter postfix expression,\npress right parenthesis ')' for ending the expression: ");

    for (i = 0; i <= SIZE - 1; i++)
    {
        scanf("%c", &postfix[i]);

        if (postfix[i] == ')')
        {
            break;
        }
    }

    evaluate(postfix);

    return 0;
}
