class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 1 2 3      7 8 9      7 4 1
        // 4 5 6  =>  4 5 6  =>  8 5 2
        // 7 8 9      1 2 3      9 6 3

        int n = matrix.size();
        for (int x = 0; x < n / 2; x++) {
            for (int y = 0; y < n; y++) {
                int idx = n - x - 1;
                swap(matrix[x][y], matrix[idx][y]);
            }
        }

        for (int x = 0; x < n; x++) {
            for (int y = x; y < n; y++)    {
                swap(matrix[x][y], matrix[y][x]);
            }
        }
    }
};
