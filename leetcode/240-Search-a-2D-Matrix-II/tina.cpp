class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int x = m - 1;
        int y = 0;
        
        while (x >= 0 && y < n) {
            if (target == matrix[x][y]) {
                return true;
            }
            
            if (target < matrix[x][y]) {
                x--;
            } else {
                y++;
            }
        }
        
        return false;
    }
};
