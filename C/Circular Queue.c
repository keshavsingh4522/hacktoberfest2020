#include <stdio.h>
#include <stdlib.h>
#define n MAX_SIZE
int MAX_SIZE = 10;
int cq[n];
int first = -1;
int last = -1;

void second(void)
{
	system("cls"); //For Windows
	// clrscr(); //For Mac/Linux
	printf("\n=====================================================================================================================================");
	printf("\n\t\t\t\t    __  ___           __      __                   __   __  __ ___ __ __  __   __  ___");
	printf("\n\t\t\t\t|_/|__)| | ||_/   /\\ / _  /\\ |__)|  | /\\ |     /| (__\\ |__)|__) | /  (_  /  \\ /__    /");
	printf("\n\t\t\t\t| \\| \\ | | || \\  /--\\\\__)/--\\| \\ |/\\|/--\\|__    |  __/ |__)|__) | \\____) \\__/ \\__)  / ");
	printf("\n=====================================================================================================================================\n");
}

void ins()
{
	int x, item;
	if ((first == 0 && last == n - 1) || (first == last + 1))
	{
		printf("\n\t\t\t\tQueue Overflow!!\n");
		return;
	}
	printf("\n\t\t\t\tHow many elements do you want to insert now? Note: Max Size Available is %d", n);
	scanf("%d", &x);
	for (int i = 1; i <= x; i++)
	{
		printf("\n\t\t\t\tInput the element for insertion in queue at pos %d : ", i);
		scanf("%d", &item);
		if (first == -1)
		{
			first = 0;
			last = 0;
		}
		else
		{
			if (last == n - 1)
				last = 0;
			else
				last += 1;
		}
		cq[last] = item;
	}
}

void del()
{
	int x;
	if (first == -1)
	{
		printf("\n\t\t\t\tQueue Underflow!!\n");
		return;
	}
	printf("\n\t\t\t\tHow many elements do you want to delete?: ");
	scanf("%d", &x);
	printf("\n\t\t\t\tElement deleted from queue : ");
	for (int i = 1; i <= x; i++)
	{
		printf(" %d ", cq[first]);
		if (first == last)
		{
			first = -1;
			last = -1;
		}
		else
		{
			if (first == n - 1)
				first = 0;
			else
				first += 1;
		}
	}
}

void disp()
{
	int first_pos = first, last_pos = last;
	if (first == -1)
	{
		printf("\n\t\t\t\tQueue is empty!!\n");
		return;
	}
	printf("\n\t\t\t\tQueue elements:: ");
	if (first_pos <= last_pos)
	{
		while (first_pos <= last_pos)
		{
			printf(" %d ", cq[first_pos]);
			first_pos++;
		}
	}
	else
	{
		while (first_pos <= n - 1)
		{
			printf(" %d ", cq[first_pos]);
			first_pos++;
		}
		first_pos = 0;
		while (first_pos <= last_pos)
		{
			printf(" %d ", cq[first_pos]);
			first_pos++;
		}
	}
	printf("\n");
}

void main()
{
	int choice, a;
	second();
	do
	{
		printf("\n\t\t\t\t===============Circular Queue Operation===============\n\n");
		printf("\n\t\t\t\tEnter Max Size of Queue: ");
		scanf("%d", &a);
		n = a;
		printf("\n\t\t\t\tMax Size Alloted to queue: %d", n);
		printf("\n\t\t\t\t1.Insert");
		printf("\n\t\t\t\t2.Delete");
		printf("\n\t\t\t\t3.Display");
		printf("\n\t\t\t\t4.Quit");
		printf("\n\t\t\t\tEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			ins();
			break;
		case 2:
			del();
			break;
		case 3:
			disp();
			break;
		case 4:
			exit(0);
		default:
			printf("\n\t\t\t\tInvalid choice!!\n");
		}
	} while (choice != 4);
}