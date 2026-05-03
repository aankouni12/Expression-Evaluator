#include "Evaluator.h"
#include "Stack.h"
#include <stdexcept>
#include <sstream>
#include <cctype>

using namespace std;

int Evaluator::precedence(string op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

bool Evaluator::isOperator(string token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool Evaluator::isNumber(string token) {
    for (int i = 0; i < token.size(); i++) {
        if (!isdigit(token[i]) && token[i] != '.')
            return false;
    }
    return !token.empty();
}

void Evaluator::infixToPostfix(string expression) {
    Stack<string> stack;
    postfixSize = 0;

    // Tokenize the expression
    string token = "";
    for (int i = 0; i <= expression.size(); i++) {
        char c = (i < expression.size()) ? expression[i] : ' ';

        if (isdigit(c) || c == '.') {
            // Build multi-digit/decimal number
            token += c;
        } else {
            // Push completed number token
            if (!token.empty()) {
                postfixTokens[postfixSize++] = token;
                token = "";
            }

            if (c == ' ') continue;

            string ch(1, c);

            if (c == '(') {
                stack.push(ch);
            } else if (c == ')') {
                // Pop until matching open paren
                while (!stack.isEmpty() && stack.peek() != "(") {
                    postfixTokens[postfixSize++] = stack.peek();
                    stack.pop();
                }
                if (!stack.isEmpty()) stack.pop(); // discard "("
            } else if (isOperator(ch)) {
                // Pop higher or equal precedence operators first
                while (!stack.isEmpty() &&
                       isOperator(stack.peek()) &&
                       precedence(stack.peek()) >= precedence(ch)) {
                    postfixTokens[postfixSize++] = stack.peek();
                    stack.pop();
                }
                stack.push(ch);
            }
        }
    }

    // Pop remaining operators
    while (!stack.isEmpty()) {
        postfixTokens[postfixSize++] = stack.peek();
        stack.pop();
    }
}

double Evaluator::evaluate() {
    ExpressionTree tree;
    tree.buildFromPostfix(postfixTokens, postfixSize);
    return tree.evaluate();
}

void Evaluator::printPostfix() {
    for (int i = 0; i < postfixSize; i++)
        cout << postfixTokens[i] << " ";
    cout << endl;
}