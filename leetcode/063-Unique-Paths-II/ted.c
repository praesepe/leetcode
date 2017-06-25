int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int ans[100][100] = {0};
    
    if (obstacleGridRowSize <= 0 || obstacleGridColSize <= 0 || obstacleGrid[0][0] == 1) {
        return 0;
    }
    
    ans[0][0] = 1;
    
    for (int i=1; i<obstacleGridColSize; i++) {
         ans[0][i] = obstacleGrid[0][i] ? 0 : ans[0][i-1];
    }
    
    for (int i=1; i<obstacleGridRowSize; i++) {
        ans[i][0] = obstacleGrid[i][0] ? 0 : ans[i-1][0];
    }
    
    for (int i=1; i<obstacleGridRowSize; i++) {
        for (int j=1; j<obstacleGridColSize; j++) {
            ans[i][j] = obstacleGrid[i][j] ? 0 : ans[i-1][j] + ans[i][j-1];
        }
    }
    
    return ans[obstacleGridRowSize-1][obstacleGridColSize-1];
}
