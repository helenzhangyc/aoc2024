#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
#include <unordered_set>
#include <cassert>
using namespace std;

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        getline(newfile, line);

        vector<int> blocks; 

        int n = line.length();
        bool is_file = true;

        int num_files = 0;

        unsigned long long sum = 0;

        for (int i = 0; i < n; ++i) {
            if (is_file) {
                num_files++;
            }
            is_file = !is_file;
            blocks.push_back(line[i] - '0');
        }

        vector<int> reallocated(blocks);

        int addr = 0;
        int end_id = num_files - 1;
        for (int i = n - 1; i >= 0; i -= 2) {
            addr = 0;
            is_file = true;
            for (int j = 0; j < i; ++j) {
                if ((!is_file) && (reallocated[j] >= blocks[i])) {
                    reallocated[j] -= blocks[i];
                    reallocated[j - 1] += blocks[i];
                    break;
                }
                is_file = !is_file;
                addr += reallocated[j];
            }

            for (int k = 0; k < blocks[i]; ++k) {
                sum += (unsigned long long)((addr + k) * end_id);
            }
            end_id--;
        }

        cout << sum << endl;
        
    }
    newfile.close();
    return 0;
}