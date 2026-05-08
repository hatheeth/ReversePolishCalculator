#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100   // Maximum stack size

// Stack implementation
float stack[MAX];
int top = -1;

// Push function
void push(float value) {
    if (top >= MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = value;
}

// Pop function
float pop() {
    if (top < 0) {
        printf("Stack underflow!\n");
        return 0;
    }
    return stack[top--];
}

// Peek top of stack
float peek() {
    if (top < 0) {
        printf("Stack empty!\n");
        return 0;
    }
    return stack[top];
}

// Evaluate Reverse Polish instructions
void evaluate(char instruction, float value) {
    float a, b;
    switch (instruction) {
        case '?':   // Push operand
            push(value);
            break;
        case '+':
            b = pop();
            a = pop();
            push(a + b);
            break;
        case '-':
            b = pop();
            a = pop();
            push(a - b);
            break;
        case '*':
            b = pop();
            a = pop();
            push(a * b);
            break;
        case '/':
            b = pop();
            a = pop();
            if (b != 0)
                push(a / b);
            else
                printf("Error: Division by zero!\n");
            break;
        case '=':   // Print top of stack
            printf("Result: %.2f\n", peek());
            break;
        default:
            printf("Unknown instruction: %c\n", instruction);
    }
}

int main() {
    // Example: ? 3 ? 4 + =
    evaluate('?', 3);
    evaluate('?', 4);
    evaluate('+', 0);
    evaluate('=', 0);

    // Example: ? 2 ? 5 + ? 7 ? 1 + * =
    evaluate('?', 2);
    evaluate('?', 5);
    evaluate('+', 0);
    evaluate('?', 7);
    evaluate('?', 1);
    evaluate('+', 0);
    evaluate('*', 0);
    evaluate('=', 0);

    return 0;
}
