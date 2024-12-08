#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <regex>
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
        while (getline(newfile, line))
        {
            grid.push_back(line);
        }
        int row = grid.size();
        int col = grid[0].size();
        unordered_map<char, vector<pair<int, int>>> locations;
        unordered_set<int> antinode_locations;

        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < col; ++c)
            {
                if (grid[r][c] != '.')
                {
                    locations[grid[r][c]].push_back({r, c});
                    antinode_locations.insert(r * col + c);
                }
            }
        }

        for (const auto &entry : locations)
        {
            char key = entry.first;
            const auto &vec = entry.second;
            int n = vec.size();

            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    // calculate antinode location
                    int x_diff = vec[i].first - vec[j].first;
                    int y_diff = vec[i].second - vec[j].second;

                    int x1 = vec[i].first + x_diff;
                    int x2 = vec[j].first - x_diff;

                    int y1 = vec[i].second + y_diff;
                    int y2 = vec[j].second - y_diff;

                    while (x1 >= 0 && x1 < row && y1 >= 0 && y1 < col) {
                        antinode_locations.insert(x1 * col + y1);
                        x1 += x_diff;
                        y1 += y_diff;
                    }
                    while (x2 >= 0 && x2 < row && y2 >= 0 && y2 < col) {
                        antinode_locations.insert(x2 * col + y2);
                        x2 -= x_diff;
                        y2 -= y_diff;
                    }


                }
            }
        }

        cout << antinode_locations.size() << endl;
    }
    newfile.close();
    return 0;
}