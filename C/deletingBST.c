#include <stdio.h>  
#include <stdlib.h>  

// Definition of the node structure  
struct node {  
    int data;  
    struct node *left;  
    struct node *right;  
};  

// Function to create a new tree node  
struct node *createTreeNode(int data) {  
    struct node *treeNode = (struct node*)malloc(sizeof(struct node));  
    if (!treeNode) {  
        printf("Memory Allocation Failed\n");  
        exit(1);  
    }  
    treeNode->data = data;  
    treeNode->left = NULL;  
    treeNode->right = NULL;  
    return treeNode;  
}  

// Function to insert a new node in the BST  
struct node *insert(struct node *root, int data) {  
    if (root == NULL) {  
        return createTreeNode(data);  
    }  
    if (data < root->data) {  
        root->left = insert(root->left, data);  
    } else {  
        root->right = insert(root->right, data);  
    }  
    return root;  
}  

// Function to perform in-order traversal of the BST  
void inOrderTraversal(struct node *root) {  
    if (root == NULL) {  
        return;  
    }  
    inOrderTraversal(root->left);  
    printf("%d ", root->data);  
    inOrderTraversal(root->right);  
}  

// Function to find the minimum value node in a given subtree  
struct node *minValueNode(struct node *node) {  
    struct node *current = node;  
    // Loop to find the leftmost leaf (minimum value)  
    while (current && current->left != NULL) {  
        current = current->left;  
    }  
    return current;  
}  

// Function to delete a node from the BST  
struct node *deleteNode(struct node *root, int key) {  
    // Base case: If root is NULL, return NULL  
    if (root == NULL) {  
        return root;  
    }  

    // Traverse the tree to find the node to delete  
    if (key < root->data) {  
        root->left = deleteNode(root->left, key);  
    } else if (key > root->data) {  
        root->right = deleteNode(root->right, key);  
    } else {  
        // Node with only one child or no child  
        if (root->left == NULL) {  
            struct node *temp = root->right;  
            free(root);  
            return temp;  
        } else if (root->right == NULL) {  
            struct node *temp = root->left;  
            free(root);  
            return temp;  
        }  

        // Node with two children: get the inorder successor (smallest in the right subtree)  
        struct node *temp = minValueNode(root->right);  

        // Copy the inorder successor's content to this node  
        root->data = temp->data;  

        // Delete the inorder successor  
        root->right = deleteNode(root->right, temp->data);  
    }  
    return root;  
}  

// Main function  
int main() {  
    struct node *root = NULL;  

    // Inserting nodes into the BST  
    root = insert(root, 50);  
    insert(root, 30);  
    insert(root, 20);  
    insert(root, 40);  
    insert(root, 70);  
    insert(root, 60);  
    insert(root, 80);  

    printf("Inorder Traversal of the BST before deletion:\n");  
    inOrderTraversal(root);  
    printf("\n");  

    // Deleting a node  
    printf("Enter the Key ELement to be deleted :\n");
    int key;
    scanf("%d",&key);
    root = deleteNode(root, key);  
    printf("Element (%d) Deleted\n" , key);
    printf("Inorder Traversal of the BST after deletion of %d:\n", key);  
    inOrderTraversal(root);  
    printf("\n");  

    return 0;  
}