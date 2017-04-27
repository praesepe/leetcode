#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;

		int result = 0;
		while (right >= left) {
			int middle = (left + right) / 2;
			int middleValue = nums[middle];

			if (target > middleValue) {
				left = middle + 1;
				result = left;
			} else if (target < middleValue) {
				right = middle - 1;
			} else {
				result = middle;
				break;
			}
		}

		return result;
	}
};
