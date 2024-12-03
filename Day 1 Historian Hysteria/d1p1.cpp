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
        vector<int> dist1;
        vector<int> dist2;
        while (getline(newfile, line))
        {
            cout << line << "\n";
            istringstream ss(line);
            int num1, num2;
            ss >> num1 >> num2;
            dist1.push_back(num1);
            dist2.push_back(num2);
        }
        sort(dist1.begin(), dist1.end());
        sort(dist2.begin(), dist2.end());

        int n = dist1.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += abs(dist1[i] - dist2[i]);
        }
        cout << sum << endl;
    }
    newfile.close();
    return 0;
}