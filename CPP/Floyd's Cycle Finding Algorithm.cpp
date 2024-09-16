//This C++ code is for determining if a loop or a cycle exists in a linked list or not

#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	int data;
	Node* next;
};

void push_back(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

bool isLoop(Node* list)
{
	Node *tortoise = list, *rabbit = list;

	while (tortoise && rabbit&& rabbit->next) {
		tortoise = tortoise->next;
		fast_p = rabbit->next->next;
		if (tortoise == rabbit) {
			return true;
		}
	}
	return false;
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	push_back(&head, 20);
	push_back(&head, 4);
	push_back(&head, 15);
	push_back(&head, 10);

	/* Create a loop for testing */
	head->next->next->next->next = head;
	if (detectLoop(head))
// 		 Loop found
	else
// 		No Loop
}
