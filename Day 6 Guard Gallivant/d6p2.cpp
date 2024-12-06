#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
#include <queue>
#include <tuple>
#include <unordered_set>
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
        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < col; ++c)
            {
                if (grid[r][c] == '^')
                {
                    x = r;
                    y = c;
                    break;
                }
            }
        }

        int guard_x = x;
        int guard_y = y;

        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < col; ++c)
            {
                vector<string> tmpGrid = grid;
                if (tmpGrid[r][c] != '^' && tmpGrid[r][c] != '#')
                {
                    // we can construct an obstacle here
                    tmpGrid[r][c] = '#';

                    x = guard_x;
                    y = guard_y;
                    dir_index = 0;

                    // keep track of visited states (position, direction)
                    // if there is repeat, meaning we are entering a cycle
                    // key: r * row + c, value: directions on (r, c)
                    unordered_map<int, vector<int>> visited_states;
                    visited_states[x * row + y].push_back(dir_index);

                    while (true)
                    {
                        int new_x = x + dirs[dir_index].first;
                        int new_y = y + dirs[dir_index].second;

                        if (new_x < 0 || new_x >= row || new_y < 0 || new_y >= col)
                        {
                            // Guard exits the grid
                            break;
                        }

                        if (tmpGrid[new_x][new_y] == '#')
                        {
                            // Turn right
                            dir_index = (dir_index + 1) % 4;
                        }
                        else
                        {
                            // Move forward
                            x = new_x;
                            y = new_y;

                            if (find(visited_states[x * row + y].begin(), visited_states[x * row + y].end(), dir_index) != visited_states[x * row + y].end())
                            {
                                // Loop detected
                                sum++;
                                break;
                            }
                            else
                            {
                                visited_states[x * row + y].push_back(dir_index);
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