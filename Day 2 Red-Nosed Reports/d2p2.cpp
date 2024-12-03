#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool isSafe(vector<int> numbers)
{
    // check if the entire list is increasing or decreasing
    // check if consecutive numbers differ by at least one and at most three
    bool increasing = true;
    int n = numbers.size();
    if (numbers[0] > numbers[1])
    {
        increasing = false;
    }
    if (abs(numbers[0] - numbers[1]) > 3 || abs(numbers[0] - numbers[1]) < 1)
    {
        return false;
    }
    for (int i = 2; i < n; ++i)
    {
        if (abs(numbers[i] - numbers[i - 1]) > 3 || abs(numbers[i] - numbers[i - 1]) < 1)
        {
            return false;
        }
        if (numbers[i] < numbers[i - 1] && increasing)
        {
            return false;
        }
        if (numbers[i] > numbers[i - 1] && !increasing)
        {
            return false;
        }
    }
    return true;
}

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
            
            // remove each of the index and check if it is safe
            if (isSafe(numbers)) {
                sum++;
            } else {
                int n = numbers.size();
                for (int i = 0; i < n; ++i) {
                    vector<int> newNumbers = numbers;
                    newNumbers.erase(newNumbers.begin() + i);
                    if (isSafe(newNumbers)) {
                        sum++;
                        break;
                    }
                }
            }
        }
        cout << sum << endl;
    }
    newfile.close();
    return 0;
}