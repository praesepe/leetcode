#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = 0;
		int result = INT_MIN;
		for (const auto &num : nums) {
			if (sum > 0) {
				sum += num;
			} else {
				sum = num;
			}
			result = max(result, sum);
		}

		return result;
	}
};
