#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		size_t width = obstacleGrid[0].size();
		int *dp = new int[width]();
		dp[0] = 1;

		for (size_t i = 0; i < obstacleGrid.size(); i++) {
			for (size_t j = 0; j < width; j++) {
				if (obstacleGrid[i][j] == 1) {
					dp[j] = 0;
				} else if (j > 0) {
					dp[j] += dp[j-1];
				}
			}
		}
		return dp[width-1];
    }
};
