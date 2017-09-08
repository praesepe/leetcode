#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() + 2;
        int m = 0;
        for (int i = 0; i < height.size(); i++) {
            m = max(height[i], m);
        }
        m++;

		// container
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            grid[0][i] = 1;
        }
		output(grid);

		// container with wall
		vector<int> rightMost(m);
        for (int y = 0; y < height.size(); y++) {
            for (int x = 0; x < height[y]; x++) {
                grid[x+1][y+1] = 1;
				rightMost[x+1] = y+1;
            }
        }
		output(grid);

		// calculate
		int count = 0;
		for (int y = 1; y < n - 1; y++) {
			for (int x = 1; x < m; x++) {
				// if current element is object
				if (grid[x][y] == 1) {
					continue;
				}

				// left element and buttom element euqal '1'
				if (grid[x][y-1] == 1 && grid[x-1][y] == 1 && y < rightMost[x]) {
					grid[x][y] = 1;
					count++;
				}
			}
		}
		output(grid);

		return count;
    }
private:
	void output(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		for (int x = m - 1; x >= 0; x--) {
			for (int y = 0; y < n; y++) {
				printf("%d ", grid[x][y]);
			}
			printf("\n");
		}
		printf("\n");
	}
};

int main() {
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

	Solution slt;
	int result = slt.trap(height);
	printf("result = %d\n", result);

	return 0;
}
