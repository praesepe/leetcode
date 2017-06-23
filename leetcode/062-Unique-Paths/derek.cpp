class Solution {
public:
    int uniquePaths(int m, int n) {

		// Example: m x n = 3 x 3
		// 6 3 1 0
		// 3 2 1 0
		// 1 1 1 1
		// 0 0 0 0

        // new matrix
        int** matrix = new int*[m + 1];
        for (int i = 0; i < m + 1; i++) {
            matrix[i] = new int[n + 1];
        }

        // init matrix
        for (int c = 0; c < n + 1; c++) {
            matrix[m][c] = 0;
        }
        for (int r = 0; r < m + 1; r++) {
            matrix[r][n] = 0;
        }
        matrix[m-1][n] = 1;

        // backtrack
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                matrix[r][c] = matrix[r + 1][c] + matrix[r][c + 1];
            }
        }

        // result
        int path = matrix[0][0];

        // delete matrix
        for (int i = 0; i < m + 1; i++) {
            delete [] matrix[i];
        }
        delete [] matrix;

        return path;
    }
};
