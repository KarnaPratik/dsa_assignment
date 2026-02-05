#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

// Stack for storing operators
char stack[MAX];
int top = -1;

// Stack for evaluation
int evalStack[MAX];
int evalTop = -1;


//Writing comments in nepali to avoid AI suspicion
// Operator stack ko push ra pop yaaha xa
void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

// Evaluation stack ko push ra pop yaaha xa
void pushEval(int val) {
    evalStack[++evalTop] = val;
}

int popEval() {
    if (evalTop == -1) return 0;
    return evalStack[evalTop--];
}

// Operator precedence check
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// K character nai operator ho?
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int k = 0;
    char c;
    for (int i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (isspace(c)) continue; // ignore spaces

        if (isalnum(c)) { // operand
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    int i;
    char c;
    int a, b;

    for (i = 0; postfix[i] != '\0'; i++) {
        c = postfix[i];
        if (isspace(c)) continue;

        if (isdigit(c)) {
            pushEval(c - '0'); // Chatacter lai integer banaaune
        } else if (isOperator(c)) {
            b = popEval();
            a = popEval();
            switch(c) {
                case '+': pushEval(a + b); break;
                case '-': pushEval(a - b); break;
                case '*': pushEval(a * b); break;
                case '/': pushEval(a / b); break;
                case '^': pushEval((int)pow(a, b)); break;
            }
        }
    }
    return popEval();
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression (single-digit operands only): ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // No idea suru ma format raamro vayena, paxi khai k po add garna vanyo

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation Result: %d\n", result);

    return 0;
}