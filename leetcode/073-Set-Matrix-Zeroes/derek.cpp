class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        bool zero_row = false, zero_column = false;

        // check the first row is filled in zero or not
        for (int y = 0; y < n; y++) {
            if (matrix[0][y] == 0) {
                zero_row = true;
                break;
            }
        }

        // check the first column is filled in zero or not
        for (int x = 0; x < m; x++) {
            if (matrix[x][0] == 0) {
                zero_column = true;
                break;
            }
        }

        // update zero state at the first row column
        for (int x = 1; x < m; x++) {
            for (int y = 1; y < n; y++) {
                if (matrix[x][y] == 0) {
                    matrix[0][y] = 0;
                    matrix[x][0] = 0;
                }
            }
        }

        // fill zero in matrix except the first row and column
        for (int x = 1; x < m; x++) {
            if (matrix[x][0] == 0) {
                for (int y = 1; y < n; y++) {
                    matrix[x][y] = 0;
                }
            }
        }
        for (int y = 1; y < n; y++) {
            if (matrix[0][y] == 0) {
                for (int x = 1; x < m; x++) {
                    matrix[x][y] = 0;
                }
            }
        }

        // update the first row and column
        if (zero_row) {
            for (int y = 0; y < n; y++) {
                matrix[0][y] = 0;
            }
        }
        if (zero_column) {
            for (int x = 0; x < m; x++) {
                matrix[x][0] = 0;
            }
        }
    }
};
