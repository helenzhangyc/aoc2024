#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
#include <unordered_set>
#include <cassert>
#include <queue>
using namespace std;

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        vector<vector<int>> grid;
        while (getline(newfile, line))
        {
            vector<int> tmp;
            for (char c : line)
            {
                tmp.push_back(c - '0');
            }
            grid.push_back(tmp);
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // for every 0, calculate score
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;

        int score = 0;

        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < col; ++c)
            {
                if (grid[r][c] == 0)
                {

                    q.push({r, c});
                }
            }
        }
        while (!q.empty())
        {
            pair<int, int> curr_pos = q.front();
            q.pop();
            int r = curr_pos.first;
            int c = curr_pos.second;
            if (grid[r][c] == 9)
            {
                score++;
            }
            else
            {
                for (auto d : dirs)
                {
                    int new_r = r + d.first;
                    int new_c = c + d.second;
                    if (new_r >= 0 && new_r < row && new_c >= 0 && new_c < col && grid[new_r][new_c] == grid[r][c] + 1)
                    {
                        q.push({new_r, new_c});
                    }
                }
            }
        }

        cout << score << endl;
    }
    newfile.close();
    return 0;
}