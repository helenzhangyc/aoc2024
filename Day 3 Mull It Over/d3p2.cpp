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
    string logFileName = "log.txt";
    ofstream logFile(logFileName, std::ios::app);
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        int sum = 0;
        int do_count = 0;
        int dont_count = 0;
        bool enabled = true;
        while (getline(newfile, line))
        {
            regex mul_regex(R"(mul\((\d{1,3}),(\d{1,3})\))");
            regex do_regex(R"(do\(\))");
            regex dont_regex(R"(don't\(\))");
            regex combined_regex(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))");

            smatch match;
            sregex_iterator begin(line.begin(), line.end(), combined_regex);
            sregex_iterator end;

            for (auto it = begin; it != end; ++it)
            {
                match = *it;

                if (regex_match(match.str(), do_regex))
                {
                    enabled = true;
                    do_count++;
                }
                else if (regex_match(match.str(), dont_regex))
                {
                    enabled = false;
                    dont_count++;
                }
                else if (enabled && regex_match(match.str(), mul_regex))
                {
                    int x = stoi(match[1].str());
                    int y = stoi(match[2].str());
                    sum += x * y;
                    logFile << x << " " << y << endl;
                }
            }
        }
        cout << do_count << endl;
        cout << dont_count << endl;
        cout << sum << endl;
    }
    newfile.close();
    return 0;
}