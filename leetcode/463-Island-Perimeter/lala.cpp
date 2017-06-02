#include <vector>
using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int result = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] != 1) continue;
				// left
				if (i - 1 < 0 || grid[i - 1][j] != 1) result++;
				// right
				if (i + 1 >= grid.size() || grid[i + 1][j] != 1) result++;
				// top
				if (j + 1 >= grid[i].size() || grid[i][j + 1] != 1) result++;
				// bottom
				if (j - 1 < 0 || grid[i][j - 1] != 1) result++;
			}
		}

		return result;
	}
};
