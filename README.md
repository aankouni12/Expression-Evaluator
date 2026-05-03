# Expression Evaluator

A command-line expression evaluator built in C++ that parses and evaluates mathematical expressions using a custom stack and expression tree.

## Data Structures Used
- **Stack** — custom linked list-based stack template class
- **Expression Tree** — binary tree where operators are internal nodes and operands are leaves

## How It Works
1. Takes an infix expression as input (e.g. `3 + 4 * 2`)
2. Converts it to postfix using the Shunting Yard algorithm
3. Builds an expression tree from the postfix tokens
4. Recursively evaluates the tree to produce the result

## Supported Operations
- Addition `+`
- Subtraction `-`
- Multiplication `*`
- Division `/`
- Parentheses `()`
- Multi-digit and decimal numbers

## Example
```
Enter expression: 3 + 4 * 2
Postfix:  3 4 2 * +
Result:   11

Enter expression: (3 + 4) * 2
Postfix:  3 4 + 2 *
Result:   14
```

## How to Compile and Run
```
g++ main.cpp Evaluator.cpp ExpressionTree.cpp -o main
.\main
```