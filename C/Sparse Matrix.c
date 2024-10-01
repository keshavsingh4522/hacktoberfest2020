// C program for Sparse Matrix Representation
// using Linked Lists
// Copyright @Agarwal-Kritik
#include <stdio.h>
#include <stdlib.h>

// Node to represent sparse matrix
struct Node
{
	int value;
	int row_position;
	int column_postion;
	struct Node *next;
};

// My Stylizing Watermark //

void second(void)
{
	system("cls");
	printf("\n=====================================================================================================================================");
	printf("\n\n\t\tDeveloped By:-");
	printf("\n\t\t\t    __  ___           __      __                   ");
	printf("\n\t\t\t|_/|__)| | ||_/   /\\ / _  /\\ |__)|  | /\\ |     ");
	printf("\n\t\t\t| \\| \\ | | || \\  /--\\\\__)/--\\| \\ |/\\|/--\\|__ ");
	printf("\n=====================================================================================================================================\n");
}

// Function to create new node
void create_new_node(struct Node **start, int non_zero_element,
					 int row_index, int column_index)
{
	struct Node *temp, *r;
	temp = *start;
	if (temp == NULL)
	{
		// Create new node dynamically
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->value = non_zero_element;
		temp->row_position = row_index;
		temp->column_postion = column_index;
		temp->next = NULL;
		*start = temp;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;

		// Create new node dynamically
		r = (struct Node *)malloc(sizeof(struct Node));
		r->value = non_zero_element;
		r->row_position = row_index;
		r->column_postion = column_index;
		r->next = NULL;
		temp->next = r;
	}
}

/* Function to delete the entire linked list */
void deleteList(struct Node **start)
{
	/* deref start to get the real head */
	struct Node *current = *start;
	struct Node *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	/* deref start to affect the real head back 
      in the caller. */
	*start = NULL;
}

// This function prints contents of linked list
// starting from start
void PrintList(struct Node *start)
{
	struct Node *temp, *r, *s;
	temp = r = s = start;

	printf("\n\t\t\t\t row_position: ");
	while (temp != NULL)
	{
		printf(" %d ", temp->row_position);
		temp = temp->next;
	}
	printf("\n");

	printf("\n\t\t\t\t column_postion: ");
	while (r != NULL)
	{
		printf(" %d ", r->column_postion);
		r = r->next;
	}
	printf("\n");
	printf("\n\t\t\t\t Value: ");
	while (s != NULL)
	{
		printf(" %d ", s->value);
		s = s->next;
	}
	printf("\n");
}

// Driver of the program
void main()
{
	// Assume 4x5 sparse matrix
	second();
	int k;
	int sparseMatric[4][5] =
		{
			{0, 0, 3, 0, 4},
			{0, 0, 5, 7, 0},
			{0, 0, 0, 0, 0},
			{0, 2, 6, 0, 0}};
	/* Start with the empty list */
	struct Node *start = NULL;
	printf("\n\t\t\t\t Welcome To Sparse Matrix Representation \n");
	printf("\n\t\t\t\t 1. Create dynamically \n\t\t\t\t 2. Print \n\t\t\t\t 3. Erase \n\t\t\t\t 0. Exit");
	while (1)
	{
		printf("\n\t\t\t\t Choose your option: ");
		scanf("%d", &k);
		switch (k)
		{
		case 1:

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					// Pass only those values which are non - zero
					if (sparseMatric[i][j] != 0)
						create_new_node(&start, sparseMatric[i][j], i, j);
				}
			}
			break;
		case 2:
			PrintList(start);
			break;
		case 3:
			deleteList(&start);
			printf("\n\t\t\t\t Successfully Deleted!!");
			break;
		case 0:
			exit(0);
		default:
			printf("\n\t\t\t\tWrong Choice!!\n");
		}
	}
}
