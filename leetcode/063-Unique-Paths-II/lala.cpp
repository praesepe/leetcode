#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = m > 0 ? obstacleGrid[0].size() : 0;
		int robot[100][100];

		for (int i = 0, val = 1; i < m; i++) {
			val = val & (obstacleGrid[i][0] - 1);
			robot[i][0] = val;
		}

		for (int i = 0, val = 1; i < n; i++) {
			val = val & (obstacleGrid[0][i] - 1);
			robot[0][i] = val;
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				robot[i][j] = (robot[i - 1][j] + robot[i][j - 1]) & (obstacleGrid[i][j] - 1);
			}
		}

		return m > 0 && n > 0 ? robot[m - 1][n - 1] : 0;
	}
};
