#ifndef STACK_H
#define STACK_H

#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack() {
        while (!isEmpty())
            pop();
    }

    void push(T val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop() {
        if (isEmpty())
            throw runtime_error("Pop on empty stack");
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    T peek() {
        if (isEmpty())
            throw runtime_error("Peek on empty stack");
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int getSize() {
        return size;
    }
};

#endif