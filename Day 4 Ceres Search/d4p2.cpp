#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
using namespace std;

// check if the grid with top left (r, c) satisfies X-MAS condition
bool xmas(vector<string> grid, int r, int c) {
    string diag1 = "";
    diag1 += grid[r][c];
    diag1 += grid[r + 1][c + 1];
    diag1 += grid[r + 2][c + 2];

    string diag2 = "";
    diag2 += grid[r][c + 2];
    diag2 += grid[r + 1][c + 1];
    diag2 += grid[r + 2][c];

    if ((diag1 == "MAS" || diag1 == "SAM") && (diag2 == "MAS" || diag2 == "SAM")) {
        return true;
    }
    return false;
}

// idea: for every 3x3 box, check if the diagonal is MAS
int main()
{
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string line;
        int sum = 0;
        vector<string> grid;
        while (getline(newfile, line))
        {
            grid.push_back(line);
        }
        int row = grid.size();
        int col = grid[0].length();
        for (int r = 0; r < row - 2; ++r)
        {
            for (int c = 0; c < col - 2; ++c)
            {
                if (xmas(grid, r, c)) {
                    sum++;
                }
            }
        }

        cout << sum << endl;
    }
    newfile.close();
    return 0;
}