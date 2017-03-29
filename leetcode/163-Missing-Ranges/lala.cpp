#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdint.h>
#include <stdlib.h>

#define MINIMUM_VALUE 0
#define MAXIMUM_VALUE 100

using namespace std;

class Solution {
public:
	vector<string> solve(vector<uint32_t> nums) {
		vector<string> result;
		for (uint32_t i = 0; i <= nums.size(); i++) {
			uint32_t right, left;

			if (i == nums.size()) {
				left = i == 0 ? MINIMUM_VALUE : nums[i - 1] + 1;
				right = MAXIMUM_VALUE;
			} else if (i == 0) {
				left = MINIMUM_VALUE;
				right = nums[i] - 1;
			} else {
				left = nums[i - 1] + 1;
				right = nums[i] - 1;
			}

			ostringstream ss;
			if (right > left) {
				ss << left << "->" << right;
				result.push_back(ss.str());
			} else if (right == left) {
				ss << left;
				result.push_back(ss.str());
			}
		}

		return result;
	}
};

int main() {
	Solution s;

	vector<vector<uint32_t>> testcases = {
		{},
		{ 1 },
		{ 1, 10, 50 },
		{ 1, 50, 100 },
		{ 1, 3, 4, 6, 8, 9 }
	};

	for (uint32_t i = 0; i < testcases.size(); i++) {
		cout << "Test case: " << i << endl;
		vector<string> result = s.solve(testcases[i]);

		// test case
		cout << "Data:" << endl;
		for (uint32_t j = 0; j < testcases[i].size(); j++) {
			cout << testcases[i][j]
				 << " ";
		}
		cout << endl;

		// result
		cout << "Missing range:" << endl;
		for (uint32_t j = 0; j < result.size(); j++) {
			cout << result[j]
				 << " ";
		}
		cout << endl;
		cout << "=============" << endl;
	}

	return 0;
}
