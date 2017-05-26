class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) {
            return result;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int x = 0;
        int y = -1;

        while (true) {
            // right
            for (int i = 0; i < n; i++) {
                result.push_back(matrix[x][++y]);
            }
            if (--m == 0) {
                break;
            }

            // down
            for (int i = 0; i < m; i++) {
                result.push_back(matrix[++x][y]);
            }
            if (--n == 0) {
                break;
            }

            // left
            for (int i = 0; i < n; i++) {
                result.push_back(matrix[x][--y]);
            }
            if (--m == 0) {
                break;
            }

            // up
            for (int i = 0; i < m; i++) {
                result.push_back(matrix[--x][y]);
            }
            if (--n == 0) {
                break;
            }
        }

        return result;
    }
};
