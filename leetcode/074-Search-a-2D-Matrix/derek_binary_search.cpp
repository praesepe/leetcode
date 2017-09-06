#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = m * n - 1, middle;
        int x, y;

        while (left < right) {
            middle = left + (right - left) / 2;
            x = middle / n;
            y = middle % n;

            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return false;
    }
};

int main() {
	vector<vector<int>> matrix = {{1, 3, 5}};
	int target = 0;

	Solution slt;
	slt.searchMatrix(matrix, target);
}
