
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        row = len(obstacleGrid[0])
        col = len(obstacleGrid)
        if(obstacleGrid[0][0] == 1 or obstacleGrid[col-1][row-1] == 1):
            return 0
        matrix = [[0 for i in range(row)]for j in range(col)]
        #matrix[col][row]
        flag = 0
        for i in range(row):
            if(flag == 0):
                if(obstacleGrid[0][i] != 1):
                    matrix[0][i] = 1
                else:
                    matrix[0][i] = 0
                    flag = 1
            else:
                if(flag == col):
                    return 0#no path
                matrix[0][i] = 0
                if(obstacleGrid[flag][i] == 1):
                    flag += 1
        
        
        flag = 0
        for i in range(col):
            if(flag == 0):
                if(obstacleGrid[i][0] != 1):
                    matrix[i][0] = 1
                else:
                    matrix[i][0] = 0
                    flag = 1
            else:
                if(flag == row):
                    return 0#no path
                matrix[i][0] = 0
                if(obstacleGrid[i][flag] == 1):
                    flag += 1
        
        for i in range(1,col):
            for j in range(1,row):
                if(obstacleGrid[i][j] != 1):
                    matrix[i][j] = matrix[i-1][j] + matrix[i][j-1]
                else:
                    matrix[i][j] = 0
        return matrix[col-1][row-1]
                    
                      
x = Solution()
a = [
    [0,0],
    [0,0],
    [0,0],
    [0,0],
    [0,0],
    [0,0],
    [1,0],
    [0,0],
    [0,0],
    [0,0],
    [0,0],
    [0,0],
    [1,0],
    [0,0],
    [0,0],
    [0,0],
    [0,0],
    [0,1],
    [0,0],
    [0,0],
    [1,0],
    [0,0],
    [0,0],
    [0,1],
    [0,0],
    [0,0],
    [0,0],
    [0,0],
    [0,0],
    [0,0],
    [0,0],
    [0,1],
    [0,0],
    [0,0],
    [0,0],
    [0,0],
    [1,0],
    [0,0],
    [0,0],
    [0,0],
    [0,0]
    ]
print(x.uniquePathsWithObstacles(a))

a = [
    [0,0,0,1],
    [0,1,0,0],
    [0,0,0,0]
    ]

print(x.uniquePathsWithObstacles(a))



