#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;  // Initialize head to NULL

void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main() {
    int choice = 0;
    while (choice != 9) {
        printf("\n\n********* Main Menu *********\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Random Location\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from Last\n");
        printf("6. Delete Node at Specified Location\n");
        printf("7. Search for an Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: beginsert(); break;
            case 2: lastinsert(); break;
            case 3: randominsert(); break;
            case 4: begin_delete(); break;
            case 5: last_delete(); break;
            case 6: random_delete(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Please enter a valid choice.\n");
        }
    }
    return 0;
}

void beginsert() {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &ptr->data);
    ptr->next = head;
    head = ptr;
    printf("Node inserted at beginning\n");
}

void lastinsert() {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    
    if (head == NULL) {
        head = ptr;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    printf("Node inserted at last\n");
}

void randominsert() {
    int loc, i;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    printf("Enter value: ");
    scanf("%d", &ptr->data);
    printf("Enter the position after which to insert (0 for beginning): ");
    scanf("%d", &loc);
    
    if (loc == 0) {
        ptr->next = head;
        head = ptr;
        printf("Node inserted at beginning\n");
    } else {
        struct node *temp = head;
        for (i = 0; i < loc && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(ptr);
        } else {
            ptr->next = temp->next;
            temp->next = ptr;
            printf("Node inserted\n");
        }
    }
}

void begin_delete() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from beginning\n");
}

void last_delete() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Only node deleted, list is now empty\n");
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from last\n");
}

void random_delete() {
    int loc, i;
    printf("Enter the position of the node to delete (0 for beginning): ");
    scanf("%d", &loc);
    
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (loc == 0) {
        begin_delete();
        return;
    }
    
    struct node *temp = head;
    for (i = 0; i < loc - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct node *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
    printf("Node deleted from position %d\n", loc);
}

void search() {
    int item, i = 0;
    struct node *ptr = head;
    
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter item to search: ");
    scanf("%d", &item);
    
    while (ptr != NULL) {
        if (ptr->data == item) {
            printf("Item found at position %d\n", i);
            return;
        }
        ptr = ptr->next;
        i++;
    }
    printf("Item not found\n");
}

void display() {
    struct node *ptr = head;
    
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("List contents:\n");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
