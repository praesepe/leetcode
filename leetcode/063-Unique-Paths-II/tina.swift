class Solution {
    func uniquePathsWithObstacles(_ obstacleGrid: [[Int]]) -> Int {
        if obstacleGrid.count == 0 || obstacleGrid[0].count == 0 {
            return 0
        }
        
        let row = obstacleGrid.count       
        let column = obstacleGrid[0].count
        
        var dp: [[Int]] = Array(repeating: Array(repeating: 0, count: column), count: row)
        
        dp[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1
        
        for x in stride(from: 1, to: row, by: 1) {
            dp[x][0] = (obstacleGrid[x][0] == 1) ? 0 : dp[x-1][0]
        }
        for y in stride(from: 1, to: column, by: 1) {
            dp[0][y] = (obstacleGrid[0][y] == 1) ? 0 : dp[0][y-1]
        }
        
        for x in stride(from: 1, to: row, by: 1) {
            for y in stride(from: 1, to: column, by: 1) {
                dp[x][y] = (obstacleGrid[x][y] == 1) ? 0 : dp[x-1][y] + dp[x][y-1]
            }
        }
        
        return dp[row-1][column-1]
    }
}
