class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (0 == matrix.size()) return;
        
        int n = matrix.size();
        
        // 1. A(i, j) => A(j, i)
        for (int i = 0;i < n; i++) {
            for (int j = i + 1;j < n; j++) {
                if (i == j) continue;
                
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        
        // 2. A(i, j) => A(i, n - j - 1)
        for (int i = 0;i < n; i++) {
            for (int j = 0;j < n / 2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp;
            }
        }
    }
};
