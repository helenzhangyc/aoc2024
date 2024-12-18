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

int count_corner(int x, int y, vector<string> &garden)
{
    int count = 0;
    auto type = garden[x][y];
    int row = garden.size();
    int col = garden[0].size();

    if ((x == row - 1 || garden[x + 1][y] != type) && (y == col - 1 || garden[x][y + 1] != type)) {
        count++;
    }
    if ((x == row - 1 || garden[x + 1][y] != type) && (y == 0 || garden[x][y - 1] != type)) {
        count++;
    }
    if ((x == 0 || garden[x - 1][y] != type) && (y == col - 1 || garden[x][y + 1] != type)) {
        count++;
    }
    if ((x == 0 || garden[x - 1][y] != type) && (y == 0 || garden[x][y - 1] != type)) {
        count++;
    }
    if ((x != row - 1 && garden[x + 1][y] == type) && (y != col - 1 && garden[x][y + 1] == type) && (x != row - 1 && y != col - 1 && garden[x + 1][y + 1] != type)) {
        count++;
    }
    if ((x != row - 1 && garden[x + 1][y] == type) && (y != 0 && garden[x][y - 1] == type) && (x != row - 1 && y != 0 && garden[x + 1][y - 1] != type)) {
        count++;
    }
    if ((x != 0 && garden[x - 1][y] == type) && (y != col - 1 && garden[x][y + 1] == type) && (x != 0 && y != col - 1 && garden[x - 1][y + 1] != type)) {
        count++;
    }
    if ((x != 0 && garden[x - 1][y] == type) && (y != 0 && garden[x][y - 1] == type) && (x != 0 && y != 0 && garden[x - 1][y - 1] != type)) {
        count++;
    }
    return count;
}


void bfs(vector<string> &garden, vector<vector<bool>> &visited, int startX, int startY, char type, int &area, int &corner)
{
    int row = garden.size();
    int col = garden[0].size();

    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    area = 0;
    corner = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        area++;
        corner += count_corner(x, y, garden);

        for (auto &d : dirs)
        {
            int newX = x + d.first;
            int newY = y + d.second;

            if (newX >= 0 && newX < row && newY >= 0 && newY < col)
            {
                if (garden[newX][newY] == type && !visited[newX][newY])
                {
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
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
                    int corner = 0;
                    bfs(garden, visited, r, c, garden[r][c], area, corner);
                    total_price += area * corner;
                }
            }
        }

        cout << total_price << endl;
    }
    newfile.close();
    return 0;
}