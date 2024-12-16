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

void bfs(vector<string> &garden, vector<vector<bool>> &visited, int startX, int startY, char type, int &area, int &perimeter)
{
    int row = garden.size();
    int col = garden[0].size();

    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    area = 0;
    perimeter = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        area++;

        for (auto &d : dirs)
        {
            int newX = x + d.first;
            int newY = y + d.second;

            if (newX >= 0 && newX < row && newY >= 0 && newY < col)
            {
                if (type == garden[newX][newY] && !visited[newX][newY])
                {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
                else if (garden[newX][newY] != type)
                {
                    perimeter++;
                }
            }
            else
            {
                perimeter++;
            }
        }
    }
}

int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        vector<string> garden;
        while (getline(newfile, line))
        {
            garden.push_back(line);
        }
        int row = garden.size();
        int col = garden[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int total_price = 0;

        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < col; ++c)
            {
                if (!visited[r][c])
                {
                    int area = 0;
                    int perimeter = 0;
                    bfs(garden, visited, r, c, garden[r][c], area, perimeter);
                    total_price += area * perimeter;
                }
            }
        }

        cout << total_price << endl;
    }
    newfile.close();
    return 0;
}