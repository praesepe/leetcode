#include <vector>

using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector< vector<int> > &matrix) {
		vector<int> result;
		if (matrix.size() == 0) {
			return result;
		}

		int row = 0;
		int col = -1;
		int m = matrix.size(); 
		int n = matrix[0].size();

		while (true) {
			// right
			for (int i = 0; i < n; i++) {
				result.push_back(matrix[row][++col]);
			}
			if (--m == 0) {
				break;
			}

			// down
			for (int i = 0; i < m; i++) {
				result.push_back(matrix[++row][col]);
			}
			if (--n == 0) {
				break;
			}

			// left
			for (int i = 0; i < n; i++) {
				result.push_back(matrix[row][--col]);
			}
			if (--m == 0) {
				break;
			}

			// top
			for (int i = 0; i < m; i++) {
				result.push_back(matrix[--row][col]);
			}
			if (--n == 0) {
				break;
			}
		}

		return result;
	}
};
