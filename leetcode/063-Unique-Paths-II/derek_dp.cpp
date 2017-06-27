class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>> matrix(m+1, vector<int>(n+1,0));
        matrix[0][1] = 1;

        for (int r = 1; r < m+1; r++) {
            for (int c = 1; c < n+1; c++) {
                if (obstacleGrid[r-1][c-1] == 0) {
                    matrix[r][c] = matrix[r-1][c] + matrix[r][c-1];
                }
            }
        }

        return matrix[m][n];
    }
};
