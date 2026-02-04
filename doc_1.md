## Given Question:

1. Write a program to check if any given mathematical expression has a balanced number of
parentheses or not?
Run the program by testing following expression-
⇒a + (b − c) ∗ (d
⇒m + [a − b ∗ (c + d ∗ {m)]
⇒a + (b − c)
Hint: Use stack

## Solution:

### (a) Data Strucutres Defintion

Used a stack to store opening brackets while scanning the expression.

Stack: Implemented as a character array of fixed size (MAX = 100).

The stack allows us to push a character, in this case, an opening bracket and pop them when another matching character is found, in this case, a closing bracket.

### (b) Description of Functions

void push(char ch)
Adds an element (ch) to the top of the stack.

char pop()
Removes and returns the top element from the stack.
It also returns '\0' if the stack is empty.

int isMatchingPair(char opening, char closing)

Purpose: Checks whether a pair of brackets match.

Returns: 1 if the pair matches ((), {}, []), otherwise 0.

int isBalanced(char expr[])

Purpose: Traverses a given expression and checks for balanced brackets.

It pushes every opening bracket onto the stack while ignoring other characters, when a closing bracket is found, it pops the first bracket. In the end it returns 1 if th stack is empty i.e. balanced otherwise it returns 0.


### (c) Overview of main()

Array of expressions: Holds multiple test expressions.

Loop: Iterates through each expression.

Function call: Calls isBalanced() for each expression.

Print result: Displays whether the expression is balanced or not.

### (d) Sample Output:

Expression: a + (b - c) * (d
Result: Not Balanced

Expression: m + [a - b * (c + d * {m)]
Result: Not Balanced

Expression: a + (b - c)
Result: Balanced