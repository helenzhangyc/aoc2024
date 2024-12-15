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
        istringstream iss(line);
        int num;

        unordered_map<unsigned long long, unsigned long long> stones;

        while (iss >> num)
        {
            stones[(unsigned long long)num] = 1;
        }

        for (int i = 0; i < 75; ++i)
        {
            unordered_map<unsigned long long, unsigned long long> tmp;
            for (auto pair : stones) {
                unsigned long long stone = pair.first;
                unsigned long long count = pair.second;
                if (stone == 0)
                {
                    tmp[1] += count;
                }
                else if (to_string(stone).length() % 2 == 0)
                {
                    string stone_to_str = to_string(stone);
                    int n = stone_to_str.length();
                    unsigned long long left = stoull(stone_to_str.substr(0, n / 2));
                    unsigned long long right = stoull(stone_to_str.substr(n / 2, n / 2));
                    tmp[left] += count;
                    tmp[right] += count;
                } else {
                    tmp[stone * 2024] += count;
                }
            }
            stones = tmp;
        }

        unsigned long long answer = 0;
        for (auto pair : stones) {
            answer += pair.second;
        }
        cout << answer << endl;
    }
    newfile.close();
    return 0;
}