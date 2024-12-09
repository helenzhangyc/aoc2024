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
        int curr_id = 0;
        bool is_file = true;

        // convert disk map to individual blocks
        for (int i = 0; i < n; ++i) {
            int len = line[i] - '0';
            if (is_file) {
                for (int j = 0; j < len; ++j) {
                    blocks.push_back(curr_id);
                }
                curr_id++;
            } else {
                for (int j = 0; j < len; ++j) {
                    blocks.push_back(-1);
                }
            }
            is_file = !is_file;
        }

        // move file blocks
        int blocks_length = blocks.size();
        int left = 0;
        int right = blocks_length - 1;
        while (left < right) {
            while (blocks[left] != -1) {
                left++;
            }
            while (blocks[right] == -1) {
                right--;
            }
            if (left >= right) {
                break;
            }
            swap(blocks[left], blocks[right]);
            assert(blocks[left] != -1);
            assert(blocks[right] == -1);
        }

        // calculate checksum
        unsigned long long sum = 0;
        for (int i = 0; i < blocks_length; ++i) {
            if (blocks[i] == -1) {
                break;
            }
            sum += (unsigned long long)(i * blocks[i]);
        }

        cout << sum << endl;
    }
    newfile.close();
    return 0;
}