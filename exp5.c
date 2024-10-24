#include <stdio.h>
#include <stdlib.h>  // For exit()

#define MAX 50

void insert();  // Function to insert element into the queue
void delete();  // Function to delete element from the queue
void display(); // Function to display elements of the queue

int queue_array[MAX];  // Array for the queue
int rear = -1;  // Rear of the queue
int front = -1; // Front of the queue

int main() {  // Corrected the return type of main
    int choice;
    while (1) {  // Infinite loop to display menu until exit
        printf("1. Insert element to queue \n");
        printf("2. Delete element from queue \n");
        printf("3. Display all elements of queue \n");
        printf("4. Quit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();  // Call insert function
                break;
            case 2:
                delete();  // Call delete function
                break;
            case 3:
                display();  // Call display function
                break;
            case 4:
                exit(0);  // Exit the program
            default:
                printf("Wrong choice \n");  // Invalid input
        }
    }
    return 0;  // Return statement for main
}

void insert() {
    int add_element;
    if (rear == MAX - 1) {  // Check if the queue is full
        printf("Queue is Overflow \n");
    } else {
        if (front == -1) {  // If the queue is initially empty
            front = 0;
        }
        printf("Insert the element in queue: ");
        scanf("%d", &add_element);
        rear = rear + 1;  // Increment rear
        queue_array[rear] = add_element;  // Add the element
    }
}

void delete() {
    if (front == -1 || front > rear) {  // Check if the queue is empty
        printf("Queue is Underflow \n");
    } else {
        printf("Element deleted from queue is: %d\n", queue_array[front]);
        front = front + 1;  // Move front forward
    }
}

void display() {
    int i;
    if (front == -1) {  // Check if the queue is empty
        printf("Queue is empty \n");
    } else {
        printf("Queue is: \n");
        for (i = front; i <= rear; i++) {  // Loop to print queue elements
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
}
    