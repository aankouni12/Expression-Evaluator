#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <string>
#include <iostream>

using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;

    Node(string val) : value(val), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
private:
    Node* root;

    double evaluate(Node* node);
    void destroy(Node* node);
    void inorder(Node* node);

public:
    ExpressionTree() : root(nullptr) {}

    ~ExpressionTree() {
        destroy(root);
    }

    void buildFromPostfix(string tokens[], int size);
    double evaluate();
    void printInorder();
};

#endif