#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary search tree
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) // Corrected: '==' instead of '='
        return createNode(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    return root;
}

// Function to perform an in-order traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to search for a value in the binary search tree
struct Node* searchNode(struct Node* root, int value) {
    if (root == NULL || root->data == value) // Corrected: '==' instead of '='
        return root;
    if (root->data < value)
        return searchNode(root->right, value);
    return searchNode(root->left, value);
}

int main() {
    struct Node* root = NULL;
    int n, i, value, searchValue, choice;

    // Input: Number of elements to insert into the BST
    printf("Enter the number of elements you want to insert into the BST: ");
    scanf("%d", &n);

    // Input: Elements to insert into the BST
    printf("Enter the elements to insert into the BST:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    // Menu-driven operations
    while (1) {
        printf("\nMenu:\n");
        printf("1. Search for an element in the BST\n");
        printf("2. Display In-Order Traversal of BST\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Search for a value in the BST
                printf("Enter the value to search: ");
                scanf("%d", &searchValue);
                if (searchNode(root, searchValue) != NULL)
                    printf("Value %d is found in the BST.\n", searchValue);
                else
                    printf("Value %d is not found in the BST.\n", searchValue);
                break;

            case 2:
                // Display the in-order traversal of the BST
                printf("In-Order Traversal of BST: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                // Exit the program
                printf("Exiting...\n");
                exit(0);

            default:
                // Handle invalid input
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
