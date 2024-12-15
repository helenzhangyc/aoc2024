#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
#include <unordered_set>
#include <cassert>
#include <queue>
using namespace std;

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        getline(newfile, line);
        vector<unsigned long long> stones;
        istringstream iss(line);
        int num;
        while (iss >> num)
        {
            stones.push_back(num);
        }

        for (int i = 0; i < 25; ++i)
        {
            int num_of_stone = stones.size();
            for (int j = 0; j < num_of_stone; ++j)
            {
                if (stones[j] == 0)
                {
                    stones[j] = 1;
                }
                else if (to_string(stones[j]).length() % 2 == 0)
                {
                    string stone_to_str = to_string(stones[j]);
                    int n = stone_to_str.length();
                    unsigned long long left = stoull(stone_to_str.substr(0, n / 2));
                    unsigned long long right = stoull(stone_to_str.substr(n / 2, n / 2));
                    stones[j] = left;
                    stones.insert(stones.begin() + j + 1, right);
                    j++;
                    num_of_stone++;
                } else {
                    stones[j] = stones[j] * 2024;
                }
            }
        }

        cout << stones.size() << endl;
    }
    newfile.close();
    return 0;
}