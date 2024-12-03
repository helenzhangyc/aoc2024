#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
using namespace std;

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        unsigned long long sum = 0;
        while (getline(newfile, line))
        {
            regex mul_regex(R"(mul\((\d{1,3}),(\d{1,3})\))");
            smatch match;
            auto begin = sregex_iterator(line.begin(), line.end(), mul_regex);
            auto end = sregex_iterator();
            for (auto it = begin; it != end; ++it) {
                match = *it;
                int x = stoi(match[1].str());
                int y = stoi(match[2].str());
                sum += (unsigned long long)(x * y);
            }
        }
        cout << sum << endl;
    }
    newfile.close();
    return 0;
}