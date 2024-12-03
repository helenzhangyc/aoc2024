#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        vector<int> left;
        vector<int> right;
        while (getline(newfile, line))
        {
            istringstream ss(line);
            int num1, num2;
            ss >> num1 >> num2;
            left.push_back(num1);
            right.push_back(num2);
        }

        unordered_map<int, int> freq;
        int n = left.size();
        for (int i = 0; i < n; ++i) {
            freq[right[i]]++;
        }

        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += freq[left[i]] * left[i];
        }
        cout << sum << endl;
    }
    newfile.close();
    return 0;
}