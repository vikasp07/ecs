#include <stdio.h>
#include <stdlib.h>

int a[20]; // integer array of 20 elements
int n, val, i, pos;

/* Function Prototypes */
void create();   // function to create an array
void display();  // function to display elements
void insert();   // function to insert elements
void deleteElement(); // function to delete elements

int main() {
    int choice;
    while (1) {
        printf("\n\n--------MENU-------\n");
        printf("1.CREATE \n");
        printf("2.DISPLAY \n");
        printf("3.INSERT \n");
        printf("4.DELETE \n");
        printf("5.EXIT \n");
        printf("----------------\n");
        printf("ENTER YOUR CHOICE :\t");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice:\n");
        }
    }
    return 0;
}

/* Function to create an array */
void create() {
    printf("\nEnter the size of the array: \t");
    scanf("%d", &n);
    printf("\nEnter %d elements of the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

/* Function to display the array */
void display() {
    printf("\nThe array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

/* Function to insert an element into the array */
void insert() {
    printf("\nEnter the position for the new element:\t");
    scanf("%d", &pos);
    if (pos < 0 || pos > n) {
        printf("\nInvalid position!\n");
        return;
    }
    printf("\nEnter the element to be inserted:\t");
    scanf("%d", &val);
    for (i = n - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }
    a[pos] = val;
    n = n + 1;
}

/* Function to delete an element from the array */
void deleteElement() {
    printf("\nEnter the position of the element to be deleted:\t");
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("\nInvalid position!\n");
        return;
    }
    val = a[pos];
    for (i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n = n - 1;
    printf("\nThe deleted element is: %d\n", val);
}
