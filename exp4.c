#include <stdio.h>
#include <string.h>
#include <ctype.h>  // For checking if a character is a digit

void sum();
void diff();
void mult();
void div();
void power();
int stack[50], top = -1;

int main() {
    char st[50];  // Increased size to accommodate longer expressions
    int i, num;

    printf("Enter the postfix expression: ");
    scanf("%[^\n]s", st);  // Reads until newline to include the entire expression

    for (i = 0; st[i] != '\0'; i++) {
        if (st[i] == ' ') {
            continue;  // Skip spaces in the expression
        }

        if (isdigit(st[i])) {
            num = 0;
            // Handling multi-digit numbers
            while (isdigit(st[i])) {
                num = num * 10 + (st[i] - '0');
                i++;
            }
            i--;  // Adjust i to point to the last digit of the number
            top++;
            stack[top] = num;  // Push number to stack
        } else {
            switch (st[i]) {
                case '+':
                    sum();
                    break;
                case '-':
                    diff();
                    break;
                case '*':
                    mult();
                    break;
                case '/':
                    div();
                    break;
                case '^':
                    power();
                    break;
                default:
                    printf("Invalid character in expression: %c\n", st[i]);
                    return 1;
            }
        }
    }

    printf("\nThe result is = %d\n", stack[top]);  // The final result is at the top of the stack
    return 0;
}

void sum() {
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    res = op2 + op1;
    top++;
    stack[top] = res;
}

void diff() {
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    res = op2 - op1;  // Ensure op2 - op1 (order matters in subtraction)
    top++;
    stack[top] = res;
}

void mult() {
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;
    res = op2 * op1;
    top++;
    stack[top] = res;
}

void div() {
    int res, op1, op2;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;

    if (op1 == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }

    res = op2 / op1;  // Ensure op2 / op1 (order matters in division)
    top++;
    stack[top] = res;
}

void power() {
    int res = 1, op2, op1, i;
    op1 = stack[top];
    top--;
    op2 = stack[top];
    top--;

    for (i = 0; i < op1; i++) {
        res = res * op2;
    }

    top++;
    stack[top] = res;
}
