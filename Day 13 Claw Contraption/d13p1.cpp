#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

struct Machine {
    int ax;
    int ay;
    int bx;
    int by;
    int px;
    int py;
};

int minTokens(Machine &machine) {
    int minCost = numeric_limits<int>::max();

    // each button would need to be pressed no more than 100 times to win a prize
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            int x = i * machine.ax + j * machine.bx;
            int y = i * machine.ay + j * machine.by;
            if (x == machine.px && y == machine.py) {
                int cost = i * 3 + j * 1;
                minCost = min(minCost, cost);
            }
        }
    }

    if (minCost == numeric_limits<int>::max()) {
        return -1;
    } else {
        return minCost;
    }
}

int main() {
    ifstream inputFile("input.txt");
    vector<Machine> machines;
    string line;
    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }
        Machine machine;
        sscanf(line.c_str(), "Button A: X+%d, Y+%d", &machine.ax, &machine.ay);
        getline(inputFile, line);
        sscanf(line.c_str(), "Button B: X+%d, Y+%d", &machine.bx, &machine.by);
        getline(inputFile, line);
        sscanf(line.c_str(), "Prize: X=%d, Y=%d", &machine.px, &machine.py);
        machines.push_back(machine);
    }

    int totalTokens = 0;

    for (auto m : machines) {
        int cost = minTokens(m);
        if (cost != -1) {
            totalTokens += cost;
        }
    }

    cout << totalTokens << endl;

    inputFile.close();
    return 0;
}