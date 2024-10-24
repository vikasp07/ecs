#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* insert(struct Node* head, int data);
struct Node* delete(struct Node* head, int data);
void printList(struct Node* head);

int main() {
    struct Node* head = NULL; // Initialize the head of the linked list
    int choice, data;

    while (1) {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Print\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                head = insert(head, data); // Use single pointer, and update head
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                head = delete(head, data); // Use single pointer, and update head
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Function to insert a node at the end of the list
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Insert new node at the end
    }

    printf("Node with value %d inserted.\n", data);
    return head; // Return updated head
}

// Function to delete a node with a specific value
struct Node* delete(struct Node* head, int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If the list is empty
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    // If the head node holds the value to be deleted
    if (temp != NULL && temp->data == data) {
        head = temp->next; // Change the head
        free(temp); // Free old head
        printf("Node with value %d deleted.\n", data);
        return head;
    }

    // Traverse the list to find the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not found in the list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", data);
        return head;
    }

    // Unlink the node from the list and free it
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", data);
    
    return head; // Return updated head
}

// Function to print the elements of the list
void printList(struct Node* head) {
    struct Node* temp = head;

    // If the list is empty
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
