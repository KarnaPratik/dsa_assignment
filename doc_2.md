## Given Question:

2. Write a program to convert an infix mathematical expression to postfix and evaluate it.

## Solution:

### (a) Data Structures Definition

Operator stack: character array used to store operators while converting infix to postfix.

Evaluation stack: integer array used to store operands during postfix evaluation.

top and evalTop track the top index of each stack.

### (b) Fuction yaaha explain garya xu:

push(char c): pushes an operator onto the operator stack.

pop(): pops the top operator from the operator stack.

peek(): returns the top operator without popping.

pushEval(int val): pushes an integer onto the evaluation stack.

popEval(): pops an integer from the evaluation stack.

precedence(char op): returns the precedence of operators (^ > *// > +/-).

isOperator(char c): checks if a character is an operator.

infixToPostfix(char infix[], char postfix[]): converts an infix expression to postfix.

evaluatePostfix(char postfix[]): evaluates a postfix expression and returns the result.

### (c) main() here:

Reads an infix expression from the user.

Calls infixToPostfix to convert the expression to postfix.

Prints the postfix expression.

Calls evaluatePostfix to compute the result.

Prints the evaluation result.

### (d) Sample Output

Enter an infix expression (single-digit operands only): (2+3)*4

Postfix Expression: 23+4*

Evaluation Result: 20