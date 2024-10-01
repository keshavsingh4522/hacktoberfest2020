/* infix to prefix conversion*/

#include <stdio.h>
#include <string.h>
#define MAX 20
char stack[MAX];
int top = -1;
void push(char item)
{
	top++;
	stack[top] = item;
}
char pop()
{
	char a;
	a = stack[top];
	top--;
	return a;
}
int prcd(char symbol)
{
	switch (symbol)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 4;
	case '^':
	case '$':
		return 6;
	case '(':
	case ')':
	case '#':
		return 1;
	}
	return 0;
}
int isoperator(char symbol)
{
	switch (symbol)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '$':
	case '(':
	case ')':
		return 1;
	default:
		return 0;
	}
}
void infix_to_prefix(char infix[], char prefix[])
{
	int i, symbol, j = 0;
	char test[MAX];
	infix = strrev(infix);
	stack[++top] = '#';
	for (i = 0; i < strlen(infix); i++)
	{
		symbol = infix[i];
		if (isoperator(symbol) == 0)
		{
			prefix[j] = symbol;
			j++;
		}
		else
		{
			if (symbol == ')')
			{
				push(symbol);
			}
			else if (symbol == '(')
			{
				while (stack[top] != ')')
				{
					prefix[j] = pop();
					j++;
				}
				pop();
			}
			else
			{
				if (prcd(symbol >= prcd(stack[top])))
				{
					push(symbol);
				}
				else
				{
					while (prcd(symbol) < prcd(stack[top]))
					{
						prefix[j] = pop();
						j++;
					}
					push(symbol);
				}
			}
		}
	}
	while (stack[top] != '#')
	{
		prefix[j] = pop();
		j++;
	}
	prefix[j] = '\0';
	prefix = strrev(prefix);
}

/*The driver code*/
int main(void)
{
	char infix[20], prefix[20];
	printf("\nenter infix expression:");
	scanf("%s", infix);
	infix_to_prefix(infix, prefix);
	printf("\nequivalent prefix expression:");
	puts(prefix);
	return 0;
}
