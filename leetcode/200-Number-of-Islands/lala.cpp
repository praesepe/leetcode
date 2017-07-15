#include <vector>
#include <queue>

using namespace std;

struct Location {
	int x;
	int y;

	Location(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class Solution {
private:
	void set_color(vector<vector<char>>& grid, queue<Location> &q, int rows, int columns, int x, int y) {
		if (x < 0 || y < 0) return;
		if (x >= rows || y >= columns) return;
		if (grid[x][y] == '0') return;

		q.push(Location(x, y));
		grid[x][y] = '0';
	}

	void coloring(vector<vector<char>>& grid, int rows, int columns, int x, int y) {
		queue<Location> q;
		set_color(grid, q, rows, columns, x, y);

		while (!q.empty()) {
			Location l = q.front();

			set_color(grid, q, rows, columns, l.x - 1, l.y);
			set_color(grid, q, rows, columns, l.x + 1, l.y);
			set_color(grid, q, rows, columns, l.x, l.y - 1);
			set_color(grid, q, rows, columns, l.x, l.y + 1);

			q.pop();
		}
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0) return 0;

		int rows = grid.size();
		int columns = grid[0].size();
		int count = 0;
		for (size_t i = 0; i < grid.size(); i++) {
			for (size_t j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == '0') continue;
				coloring(grid, rows, columns, i, j);
				count++;
			}
		}

		return count;
	}
};
