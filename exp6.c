#include <stdio.h>
#define CAPACITY 6  // Defining the capacity of the circular queue

int queue[CAPACITY];  // Array for the circular queue
int front = -1, rear = -1;

// Function to check if the circular queue is full
int checkFull() {
    if ((front == rear + 1) || (front == 0 && rear == CAPACITY - 1)) {
        return 1;
    }
    return 0;
}

// Function to check if the circular queue is empty
int checkEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

// Function to add an element to the circular queue
void enqueue(int value) {
    if (checkFull()) {
        printf("Overflow condition\n");
    } else {
        if (front == -1) {  // Insert the first element
            front = 0;
        }
        rear = (rear + 1) % CAPACITY;  // Move rear forward circularly
        queue[rear] = value;
        printf("%d was enqueued to circular queue\n", value);
    }
}

// Function to remove an element from the circular queue
int dequeue() {
    int variable;
    if (checkEmpty()) {
        printf("Underflow condition\n");
        return -1;
    } else {
        variable = queue[front];
        if (front == rear) {  // If only one element was in the queue
            front = rear = -1;  // Reset the queue after dequeuing
        } else {
            front = (front + 1) % CAPACITY;  // Move front forward circularly
        }
        printf("%d was dequeued from circular queue\n", variable);
        return variable;
    }
}

// Function to display the circular queue
void print() {
    int i;
    if (checkEmpty()) {
        printf("Nothing to dequeue\n");
    } else {
        printf("\nThe queue looks like: \n");
        for (i = front; i != rear; i = (i + 1) % CAPACITY) {
            printf("%d ", queue[i]);
        }
        printf("%d \n\n", queue[i]);  // Printing the last element
    }
}

int main() {
    // Dequeue from an empty queue (underflow condition)
    dequeue();  
    
    // Enqueue elements into the circular queue
    enqueue(15);
    enqueue(20);
    enqueue(25);
    enqueue(30);
    enqueue(35);

    // Print the queue contents
    print();

    // Dequeue a couple of elements
    dequeue();
    dequeue();

    // Print the queue again
    print();

    // Enqueue more elements into the circular queue
    enqueue(40);
    enqueue(45);
    enqueue(50);
    
    // Attempt to enqueue one more element (overflow condition)
    enqueue(55);  // Overflow condition should occur here

    // Print the final state of the queue
    print();

    return 0;
}
