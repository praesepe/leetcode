#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }

        int count = 0;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[x].size(); y++) {
                if (grid[x][y] == '1') {
                    dfs(x, y, grid);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (grid[x][y] == '0') {
            return;
        }

        grid[x][y] = '0';

        // up
        if (x-1 >= 0) {
            dfs(x-1, y, grid);
        }

        // right
        if (y+1 < grid[0].size()) {
            dfs(x, y+1, grid);
        }

        // down
        if (x+1 < grid.size()) {
            dfs(x+1, y, grid);
        }

        // left
        if (y-1 >= 0) {
            dfs(x, y-1, grid);
        }
    }
};


int main()
{
	vector<char> x0 = {'1', '1', '0', '0', '0'};
	vector<char> x1 = {'1', '1', '0', '0', '0'};
	vector<char> x2 = {'0', '0', '1', '0', '0'};
	vector<char> x3 = {'0', '0', '0', '1', '1'};
	vector<vector<char>> grid = {x0, x1, x2, x3};

	Solution slt;
	int count = slt.numIslands(grid);

	printf("count = %d\n", count);

	return 0;
}
