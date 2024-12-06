#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
#include <queue>
using namespace std;

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        vector<string> grid;
        int sum = 0;

        while (getline(newfile, line))
        {
            grid.push_back(line);
        }

        int row = grid.size();
        int col = grid[0].size();

        // guard location
        int x = 0;
        int y = 0;

        // up, right, down, left
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int dir_index = 0;

        // update guard location
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (grid[r][c] == '^') {
                    x = r;
                    y = c;
                    break;
                }
            }
        }

        grid[x][y] = 'X';

        while (!((x == 0) || (x == row - 1) || (y == 0) || (y == col - 1))) {
            int new_x = x + dirs[dir_index].first;
            int new_y = y + dirs[dir_index].second;

            // obstacle
            if (grid[new_x][new_y] == '#') {
                dir_index++;
                if (dir_index == 4) {
                    dir_index = 0;
                }
            } else {
                x = new_x;
                y = new_y;
                grid[x][y] = 'X';
            }
        }

        // count number of 'X' in grid
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (grid[r][c] == 'X') {
                    sum++;
                }
            }
        }

        cout << sum << endl;
    }
    newfile.close();
    return 0;
}