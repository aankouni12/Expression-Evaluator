#include "ExpressionTree.h"
#include "Stack.h"
#include <stdexcept>

using namespace std;

bool isOperator(string token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

void ExpressionTree::buildFromPostfix(string tokens[], int size) {
    Stack<Node*> stack;

    for (int i = 0; i < size; i++) {
        Node* newNode = new Node(tokens[i]);

        if (isOperator(tokens[i])) {
            newNode->right = stack.peek();
            stack.pop();
            newNode->left = stack.peek();
            stack.pop();
        }

        stack.push(newNode);
    }

    root = stack.peek();
}

double ExpressionTree::evaluate(Node* node) {
    if (node == nullptr)
        throw runtime_error("Empty tree");

    if (!isOperator(node->value))
        return stod(node->value);

    double left  = evaluate(node->left);
    double right = evaluate(node->right);

    if (node->value == "+") return left + right;
    if (node->value == "-") return left - right;
    if (node->value == "*") return left * right;
    if (node->value == "/") {
        if (right == 0)
            throw runtime_error("Division by zero");
        return left / right;
    }

    throw runtime_error("Unknown operator");
}

double ExpressionTree::evaluate() {
    return evaluate(root);
}

void ExpressionTree::inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}

void ExpressionTree::printInorder() {
    inorder(root);
    cout << endl;
}

void ExpressionTree::destroy(Node* node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}