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
        string target = "XMAS";
        int sum = 0;
        vector<string> grid;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        while (getline(newfile, line))
        {
            grid.push_back(line);
        }
        int row = grid.size();
        int col = grid[0].length();
        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < col; ++c)
            {

                if (grid[r][c] == 'X')
                {
                    for (auto dir : directions)
                    {
                        int x = r;
                        int y = c;
                        for (int i = 1; i <= 3; ++i)
                        {
                            x += dir.first;
                            y += dir.second;
                            if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == target[i])
                            {
                                if (i == 3)
                                {
                                    sum++;
                                }
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }

        cout << sum << endl;
    }
    newfile.close();
    return 0;
}