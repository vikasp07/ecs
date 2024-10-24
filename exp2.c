#include<stdio.h>

int stack[100], choice, n, top, x, i;

void push(void);
void pop(void);
void display(void);

int main() {
    top = -1; // Initialize top to -1 to represent an empty stack
    printf("\n Enter the size of STACK[MAX=100]: ");
    scanf("%d", &n);
    
    if (n > 100 || n <= 0) {
        printf("\n Invalid stack size! Please enter a size between 1 and 100.\n");
        return 0; // Exit if an invalid size is entered
    }

    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");

    do {
        printf("\n Enter the Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                push();
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                printf("\n\t EXIT POINT\n");
                break;
            }
            default: {
                printf("\n\t Please Enter a Valid Choice (1/2/3/4)\n");
            }
        }
    } while (choice != 4); // Loop until user chooses to exit

    return 0;
}

void push() {
    if (top >= n - 1) { // Check if stack is full
        printf("\n\t STACK is overflow\n"); 
    } else {
        printf("\n Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x; // Insert element into stack
        printf("\n\t Value pushed: %d\n", x);
    }
}

void pop() {
    if (top <= -1) { // Check if stack is empty
        printf("\n\t STACK is underflow\n");
    } else {
        printf("\n\t The popped element is %d\n", stack[top]);
        top--; // Remove the top element
    }
}

void display() {
    if (top >= 0) { // Check if stack is not empty
        printf("\n The elements in STACK are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]); // Display elements from top to bottom
        }
    } else {
        printf("\n The STACK is empty\n");
    }
}
