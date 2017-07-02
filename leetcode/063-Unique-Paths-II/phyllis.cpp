class Solution {
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size();
        int cols[n];
     
 	if(m == 0) 
            return 0;
        
        // matrix has only one row 
        if(m == 1) {
            for(auto c : obstacleGrid[0]){
               if(c^1 == 0) return 0;
            }
            
            return 1;
        }
        
        // matrix has only one column 
        if (n == 1) {
            for(auto r : obstacleGrid){
               if(r[0]^1 == 0) return 0;
            }
            
            return 1; 
        }
        
        // unique path through first row
        cols[0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        for(int i = 1; i < n; i++){
            cols[i] = (cols[i-1] == 0) ? 0 : obstacleGrid[0][i]^1;
        }
        
	for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == 0 ){
                    if(obstacleGrid[i][0] == 1)
			cols[0] = 0;
                } else if(obstacleGrid[i][j] != 1){
                    cols[j] = cols[j-1] + cols[j];
                } else {
                    cols[j] = 0;
                }    
            }
        }
	
	return cols[n-1];
    }
};
