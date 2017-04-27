#include <vector>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0) {
			return INT_MIN;
		}

		int currentMax = nums[0];
		int currentMin = nums[0];
		int result = nums[0];
		for (size_t i = 1; i < nums.size(); i++) {
			int tMax = currentMax;
			int tMin = currentMin;

			currentMax = max(max(nums[i], tMax * nums[i]), tMin * nums[i]);
			currentMin = min(min(nums[i], tMax * nums[i]), tMin * nums[i]);

			result = max(result, currentMax);
		}


		return result;
	}
};
