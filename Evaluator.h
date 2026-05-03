#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <string>
#include "ExpressionTree.h"

using namespace std;

class Evaluator {
private:
    string postfixTokens[100];
    int postfixSize;

    // Returns operator precedence
    int precedence(string op);

    // Check if token is an operator
    bool isOperator(string token);

    // Check if token is a number
    bool isNumber(string token);

public:
    Evaluator() : postfixSize(0) {}

    // Convert infix string to postfix tokens
    void infixToPostfix(string expression);

    // Build and evaluate the expression tree
    double evaluate();

    // Print postfix tokens
    void printPostfix();
};

#endif