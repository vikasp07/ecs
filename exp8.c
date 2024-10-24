#include <stdio.h>
#include <stdlib.h>

// Define the structure of the node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node in the binary tree
struct node* create(int val) {
    struct node* newnode;
    int left, right;

    if (val == 0) // If value is 0, no node is created (empty subtree)
        return NULL;

    // Allocate memory for the new node
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    
    // Prompt and read the left child
    printf("Enter the left node of %d (0 for no left node): ", val);
    scanf("%d", &left);
    newnode->left = create(left); // left node is updated with address
    
    // Prompt and read the right child
    printf("Enter the right node of %d (0 for no right node): ", val);
    scanf("%d", &right);
    newnode->right = create(right); // right node is updated with address

    return newnode; // return the address of this node
}

// Function to display the tree in preorder (root-left-right)
void displayTree(struct node* root) {
    if (root == NULL) {
        return;
    }
    
    // Print the data of the node
    printf("%d ", root->data);

    // Recursively print the left and right children
    displayTree(root->left);
    displayTree(root->right);
}

int main() {
    struct node* root = NULL;
    int rootValue;

    printf("Enter the root node value: ");
    scanf("%d", &rootValue);

    // Create the binary tree starting with the root node
    root = create(rootValue);

    printf("Complete tree in preorder is:\n");
    displayTree(root);
    
    return 0;
}
