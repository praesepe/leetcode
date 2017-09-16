#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;

        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;

        while (right >= left) {
            int middle = left + (right - left) / 2;
            int x = middle / matrix[0].size();
            int y = middle % matrix[0].size();

            if (target > matrix[x][y]) {
                left = middle + 1;
            } else if (target < matrix[x][y]) {
                right = middle - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
