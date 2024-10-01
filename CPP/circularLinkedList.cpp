// Circular Linked List
#include<stdio.h>
#include<stdlib.h>
struct linked_list{
	int info;
	struct linked_list *next;
};

typedef struct linked_list l;
l *start, *node, *temp;

void traversal(){
	l *t;
	t = start;
	while(t -> next != start){
		printf("%d\t", t -> info);
		t = t -> next;
	}
	printf("%d\t", t -> info);
	printf("\n\n");
	
}

void insert_beg(int data){
	l * t;
	t = start;
	node = (l*) malloc(sizeof(l));
	node -> info = data;
	while(t -> next != start)
		t = t -> next;
	t -> next = node;
	node -> next = start;
	start = node;	
}

void insert_loc(int loc, int data){
	l * t;
	t = start;
	node = (l*) malloc(sizeof(l));
	node -> info = data;
	int i = 1;
	while(i < loc - 1){
		t = t -> next;
		i++;
	}
	node -> next = t -> next;
	t -> next = node;	
	
}

void insert_end(int data){
	node = (l*) malloc(sizeof(l));
	node -> info = data;
	l * t;
	t = start;
	while(t -> next != start)
		t = t -> next;
	t -> next = node;
	node -> next = start;	
	
}

void delete_beg(){
	l * t;
	t = start;
	while(t -> next != start)
		t = t -> next;
	temp = start;
	start = temp -> next;
	t -> next = temp -> next;
	free(temp);
}

void delete_data(int data){
	l * t;
	t = start;
	temp = t;
	if(temp->info == data)
	{
		t = temp -> next;
		start = t;
		free(temp);
	}
	else
	{
		while(temp->info != data)
		{
			t = temp;
			temp = temp -> next;
			if(temp -> info == data)
			{
				t->next = temp->next;
				free(temp);
				return;
			}
			
		}
	}
	
}

void delete_end(){
	l * t;
	t = start;
	while(t -> next != start){
		temp = t;
		t = t -> next;
	}
	temp -> next = start;
	free(t);
}

void search(int data){
	l * t;
	t = start;
	int i = 1;
	if(t -> info == data)
		printf("%d found at first location.\n ", data);
	else{
		while(t -> info != data){
			t = t -> next;
			i++;
			if(t -> info == data){
				printf("%d found at %d location", data, i);
			}
		}
		
	}	
}

int main(){
	int ch, loc, item;
	char choice;
	start = NULL;
	do
	{
		node = (l*) malloc(sizeof(l));
		printf("Enter the data values:-\t");
		scanf("%d", &node -> info);
		if(start == NULL)
		{
			start = node;
			temp = node;
		}
		else
		{
			temp -> next = node;
			temp = node;
		}
		printf("Want to enter more values:- (Y/N):-\t");
		scanf("%s", &choice);
		printf("\n");		
	}while(choice == 'Y'||choice == 'y');
	temp -> next = start;
	
	do
	{
		printf("\t\t\t\t\t\tMENU\n\n");
		printf("1. Traversal.\n");
		printf("2. Insertion at beginning.\n");
		printf("3. Insertion at given location.\n");
		printf("4. Insertion at end.\n");
		printf("5. Deletion at beginning.\n");
		printf("6. Deletion of a specific item.\n");
		printf("7. Deletion at end.\n");
		printf("8. Search\n");
		printf("9. Quit.\n");
		printf("Enter your choice:-\t");
		scanf("%d", &ch);
		printf("\n");
		switch(ch)
		{
			case 1: printf("The traversal of data:-\n");
					traversal();
					break;
			case 2: printf("Enter the value to be inserted at the beginning:-\t");
					scanf("%d", &item);
					insert_beg(item);
					traversal();
					break;
			case 3: printf("Enter the location you want to insert the data:-\t");
					scanf("%d", &loc);
					printf("Enter the value to be inserted at the location %d:-\t", loc);
					scanf("%d", &item);
					insert_loc(loc, item);
					traversal();
					break;
			case 4: printf("Enter the value to be inserted at the end:-\t");
					scanf("%d", &item);
					insert_end(item);
					traversal();
					break;
			case 5: printf("Deletion of the element at the beginning.\n");
					delete_beg();
					traversal();
					break;
			case 6: printf("Enter the data to be deleted:-\t");
					scanf("%d", &item);
					delete_data(item);
					traversal();
					break;
			case 7: printf("Deletion at the end.\n");
					delete_end();
					traversal();
					break;
			case 8: printf("Enter the data you want to search:-\t");
					scanf("%d", &item);
					search(item);
					break;		
			case 9: exit(0);
					break;
			default: printf("Please Enter a valid choice.\n");
		}
		
	}while(ch!= 9);	
	return 0;
}
