#include <iostream>
#include <stdexcept>
#include "Evaluator.h"

using namespace std;

int main() {
    Evaluator evaluator;
    string expression;

    cout << "Expression Evaluator" << endl;
    cout << "Supported operators: + - * /" << endl;
    cout << "Supports parentheses and decimal numbers" << endl;
    cout << "Type 'quit' to exit" << endl;
    cout << "-----------------------------" << endl;

    while (true) {
        cout << "Enter expression: ";
        getline(cin, expression);

        if (expression == "quit")
            break;

        if (expression.empty())
            continue;

        try {
            evaluator.infixToPostfix(expression);

            cout << "Postfix:  ";
            evaluator.printPostfix();

            cout << "Result:   " << evaluator.evaluate() << endl;

        } catch (runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        cout << endl;
    }

    cout << "Goodbye!" << endl;
    return 0;
}