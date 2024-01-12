//  2.(b) Write a program to perform Infix to Prefix Conversion.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

char peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;  // Assuming '(' has the lowest precedence
}

// Function to reverse a string
void reverseString(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    Stack operatorStack;
    initialize(&operatorStack);

    int infixLen = strlen(infix);
    int prefixIndex = 0;

    for (int i = infixLen - 1; i >= 0; i--) {
        char currentChar = infix[i];

        if (isalnum(currentChar)) {
            prefix[prefixIndex++] = currentChar;
        } else if (currentChar == ')') {
            push(&operatorStack, currentChar);
        } else if (currentChar == '(') {
            while (!isEmpty(&operatorStack) && peek(&operatorStack) != ')') {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            pop(&operatorStack);  // Pop ')'
        } else {  // Operator
            while (!isEmpty(&operatorStack) && getPrecedence(peek(&operatorStack)) > getPrecedence(currentChar)) {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, currentChar);
        }
    }

    while (!isEmpty(&operatorStack)) {
        prefix[prefixIndex++] = pop(&operatorStack);
    }

    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression to get the final result
    reverseString(prefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
