#include "calculator.h"
#include <stdexcept>
#include <sstream>
#include <stack>

// Простейшая реализация (только + и -)
double evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    double result = 0, number = 0;
    char op = '+';

    while (iss >> number) {
        if (op == '+') result += number;
        else if (op == '-') result -= number;

        iss >> op;
    }

    return result;
}
