#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
#include <queue>
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

vector<int> topological_sort(vector<int>& number_list, unordered_map<int, vector<int>>& number_order) {
    unordered_map<int, int> in_degree;
    unordered_map<int, vector<int>> graph;

    for (int num : number_list) {
        in_degree[num] = 0;
    }
    for (int num : number_list) {
        if (number_order.find(num) != number_order.end()) {
            for (int neighbour : number_order[num]) {
                if (in_degree.find(neighbour) != in_degree.end()) {
                    graph[num].push_back(neighbour);
                    in_degree[neighbour]++;
                }
            }
        }
    }

    queue<int> q;
    for (auto& [node, degree] : in_degree) {
        if (degree == 0) {
            q.push(node);
        }
    }

    vector<int> sorted_order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        sorted_order.push_back(node);
        for (int neighbour : graph[node]) {
            in_degree[neighbour]--;
            if (in_degree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }
    return sorted_order;
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
                    if (!valid) {
                        break;
                    }
                }
                if (!valid) {
                    vector<int> new_number_list = topological_sort(number_list, number_order);
                    sum += new_number_list[n / 2];  
                }
            }
        }
        cout << sum << endl;
    }
    newfile.close();
    return 0;
}