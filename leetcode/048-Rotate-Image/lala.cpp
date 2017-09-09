#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        if (size == 0) return;

        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size / 2; j++) {
                swap(matrix[i][j], matrix[i][size - 1 - j]);
            }
        }
    }
};
