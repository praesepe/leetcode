#include <vector>

using namespace std;

class Solution {
    int findPivot(const vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (right > left && nums[left] >= nums[right]) {
            int middle = (right + left) / 2;

			if (nums[middle] > nums[right]) {
				left = middle + 1;
			} else if (nums[left] < nums[middle]) {
				right = middle;
			} else {
				left = left + 1;
			}
		}

        return left;
    }
public:
    int findMin(vector<int>& nums) {
        return nums[this->findPivot(nums)];
    }
};
