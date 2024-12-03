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
        int sum = 0;
        while (getline(newfile, line))
        {
            istringstream stream(line);
            vector<int> numbers;
            int number;

            while (stream >> number)
            {
                numbers.push_back(number);
            }
            // check if the entire list is increasing or decreasing
            // check if consecutive numbers differ by at least one and at most three
            bool safe = true;
            bool increasing = true;
            int n = numbers.size();
            if (numbers[0] > numbers[1])
            {
                increasing = false;
            }
            if (abs(numbers[0] - numbers[1]) > 3 || abs(numbers[0] - numbers[1]) < 1)
            {
                safe = false;
            }
            for (int i = 2; i < n; ++i)
            {
                if (!safe)
                {
                    break;
                }
                if (abs(numbers[i] - numbers[i - 1]) > 3 || abs(numbers[i] - numbers[i - 1]) < 1)
                {
                    safe = false;
                    break;
                }
                if (numbers[i] < numbers[i - 1] && increasing) {
                    safe = false;
                    break;
                }
                if (numbers[i] > numbers[i - 1] && !increasing) {
                    safe = false;
                    break;
                }
            }
            if (safe)
            {
                sum++;
            }
        }
        cout << sum << endl;
    }
    newfile.close();
    return 0;
}