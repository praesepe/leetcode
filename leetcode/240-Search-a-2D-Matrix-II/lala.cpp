#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;

        int n = matrix[0].size();
        if (n == 0) return false;

        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            int entry = matrix[i][j];
            if (entry > target) {
                i--;
            } else if (entry < target){
                j++;
            } else {
                return true;
            }
        }

        return false;
    }
};
