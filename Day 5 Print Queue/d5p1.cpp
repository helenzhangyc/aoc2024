#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
using namespace std;

vector<int> splitByComma(string& str) {
    vector<int> result;
    stringstream ss(str);
    string item;
    
    while (getline(ss, item, ',')) {
        result.push_back(stoi(item));
    }
    
    return result;
}

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        bool second_part = false;
        int sum = 0;
        unordered_map<int, vector<int>> number_order;

        while (getline(newfile, line))
        {
            if (line == "") {
                second_part = true;
            } else if (!second_part) {
                int first = stoi(line.substr(0, 2));
                int second = stoi(line.substr(3, 2));
                number_order[first].push_back(second);
            } else {
                vector<int> number_list = splitByComma(line);
                // for each item n in list, check if any numbers prior to n are in number_order[n]
                // if there exists any, the line is invalid
                // if the line is valid, add the middle number into sum
                int n = number_list.size();
                bool valid = true;
                for (int i = 0; i < n; ++i) {
                    int curr_number = number_list[i];
                    for (int j = 0; j < i; ++j) {
                        if (find(number_order[curr_number].begin(), number_order[curr_number].end(), number_list[j]) != number_order[curr_number].end()) {
                            valid = false;
                            break;
                        }
                    }
                }
                if (valid) {
                    sum += number_list[n / 2];
                }
            }
        }
        cout << sum << endl;
    }
    newfile.close();
    return 0;
}