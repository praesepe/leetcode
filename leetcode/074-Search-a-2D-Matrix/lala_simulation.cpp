#include <vector>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;

        int height = matrix.size();
        int width = matrix[0].size();

        int i = height - 1, j = 0;
        while (i >= 0 && j < width) {
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
