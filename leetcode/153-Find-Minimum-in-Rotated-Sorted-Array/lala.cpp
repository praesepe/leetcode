#include <vector>
using namespace std;

class Solution {
	int findPivot(const vector<int>& nums) {
		/*
		int left = 0;
		int right = nums.size() - 1;
		int result = 0;
		while (right >= left) {
			int middle = (right + left) / 2;
			int ml = middle > 0 ? nums[middle - 1] : INT_MAX;
			int mr = middle < nums.size() - 1 ? nums[middle + 1] : INT_MAX;
			if (ml >= nums[middle] && nums[middle] <= mr) {
				result = middle;
				break;
			}

			if (nums[right] > nums[middle]) {
				right = middle - 1;
			} else {
				left = middle + 1;
			}
		}

		return result;
		*/

		int left = 0;
		int right = nums.size() - 1;
		while (right > left && nums[left] > nums[right]) {
			int middle = (right + left) / 2;
			if (nums[right] > nums[middle]) {
				right = middle;
			} else {
				left = middle + 1;
			}
		}

		return left;
	}
	public:
	int findMin(vector<int>& nums) {
		return nums[this->findPivot(nums)];
	}
};
