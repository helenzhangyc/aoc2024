#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Function to evaluate an expression left-to-right, ignoring operator precedence
long long evaluateLeftToRight(const string& expression) {
    istringstream iss(expression);
    long long result, num;
    char op;

    iss >> result;
    while (iss >> op >> num) {
        if (op == '+') {
            result += num;
        } else if (op == '*') {
            result *= num;
        }
    }

    return result;
}

// Backtracking function to generate all possible expressions and check against the target
bool backtrack(const vector<long long>& numbers, size_t index, const string& currentExpression, long long target) {
    if (index == numbers.size()) {
        long long value = evaluateLeftToRight(currentExpression);
        if (value == target) {
            // match found
            return true;
        }
        return false;
    }

    // Add the current number with '+' or '*'
    bool found = false;
    found |= backtrack(numbers, index + 1, currentExpression + "+" + to_string(numbers[index]), target);
    found |= backtrack(numbers, index + 1, currentExpression + "*" + to_string(numbers[index]), target);
    return found;
}

// Function to evaluate all possible operations for a given set of numbers and target
bool evaluateAllOperations(const vector<long long>& numbers, long long target) {
    return backtrack(numbers, 1, to_string(numbers[0]), target);
}

int main() {
    ifstream inputFile("input.txt");

    string line;
    long long totalCalibrationResult = 0;

    while (getline(inputFile, line)) {
        size_t colonPos = line.find(':');

        long long target = stoll(line.substr(0, colonPos));
        string valuesPart = line.substr(colonPos + 1);

        istringstream iss(valuesPart);
        vector<long long> numbers;
        long long num;
        while (iss >> num) {
            numbers.push_back(num);
        }

        if (evaluateAllOperations(numbers, target)) {
            // match found
            totalCalibrationResult += target;
        }
    }

    cout << totalCalibrationResult << endl;

    return 0;
}
