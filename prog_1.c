#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

void push(char ch) {
    if (top >= MAX - 1) { // Check overflow
        printf("Stack overflow, can't push\n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) { // Check if stack is empty
        return '\0'; // Return end of line because pop is a char function can't return void here.
    }
    return stack[top--];
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||(opening == '[' && closing == ']') || (opening == '{' && closing == '}');
}

int isBalanced(char expr[]) {
    top = -1;  // Reset the stack in case it is already used before for another expression
    char ch, popped;
    for (int i = 0; expr[i] != '\0'; i++) {
        ch = expr[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            popped = pop();
            if (!isMatchingPair(popped, ch)) {
                return 0;  // Is not a matching pair, that means not balanced
            }
        }
    }
    return top == -1;  // If stack is balanced, all parentheses are pushed and popped simulatneously, hence it should be empty.
}

int main() {
    char expressions[][50] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };

    for (int i = 0; i < 3; i++) {
        printf("Expression: %s\n", expressions[i]);
        if (isBalanced(expressions[i])) {
            printf("Result: Balanced\n\n");
        } else {
            printf("Result: Not Balanced\n\n");
        }
    }

    return 0;
}
