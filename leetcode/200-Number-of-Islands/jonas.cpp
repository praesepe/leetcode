class Solution {
 protected:
	void visitIsland(std::vector<std::vector<char>>& grid, int i, int j) {
		int x, y;
		std::queue<std::pair<int, int>> q({{i, j}});

		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();

			if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != '1') {
				continue;
			}

			grid[x][y] = '0';
			q.push({x, y+1});
			q.push({x, y-1});
			q.push({x+1, y});
			q.push({x-1, y});
		}
	}

 public:
    int numIslands(std::vector<std::vector<char>>& grid) {
		int result = 0;
        for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == '1') {
					visitIsland(grid, i, j);
					result++;
				}
			}
		}
		return result;
    }
};
