#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		// check condition
		int total_num = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			total_num += nums[i].size();
		}
		if (total_num < r * c) return nums; 

		// init size
		vector<vector<int>> result(r);
		for (size_t i = 0; i < result.size(); i++) {
			result[i].resize(c);
		}

		// reshpae
		for (size_t i = 0; i < nums.size(); i ++) {
			for (size_t j = 0; j < nums[i].size(); j++) {
				int num = i * nums[i].size() + j;
				int x = num / c;
				int y = num % c;
				result[x][y] = nums[i][j];
			}
		}

		return result;
	}
};
