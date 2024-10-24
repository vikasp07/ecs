#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];        // Stack for operators
char infix[MAX];        // Infix expression input
char postfix[MAX];      // Postfix expression output
int top = -1;           // Stack pointer

void push(char);
char pop();
int isEmpty();
void inToPost();
void print();
int precedence(char);

int main() {
    printf("Enter the infix expression: ");
    fgets(infix, MAX, stdin);  // Using fgets instead of gets for safety
    infix[strcspn(infix, "\n")] = '\0';  // Remove trailing newline if present
    inToPost();
    print();
    return 0;
}

/* Convert infix to postfix expression */
void inToPost() {
    int i, j = 0;
    char next;
    char symbol;

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        switch (symbol) {
            case '(':                // Push '(' to stack
                push(symbol);
                break;
            case ')':                // Pop to postfix until '(' is found
                while ((next = pop()) != '(')
                    postfix[j++] = next;
                break;
            case '+':                // Operator cases
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                    postfix[j++] = pop();
                push(symbol);
                break;
            default:                 // Operand directly to postfix
                postfix[j++] = symbol;
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';  // Null terminate the postfix expression
}

/* Determine precedence of operators */
int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

/* Print the postfix expression */
void print() {
    printf("The equivalent postfix expression is: %s\n", postfix);
}

/* Push operator onto stack */
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

/* Pop operator from stack */
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

/* Check if stack is empty */
int isEmpty() {
    return top == -1;
}
