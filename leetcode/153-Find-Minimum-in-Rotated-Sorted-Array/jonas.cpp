class Solution {
public:
    int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size()-1;

		while (left < right) {
			if (nums[left] < nums[right]) {
				return nums[left];
			}

			int middle = (left + right) / 2;
			if (nums[middle] >= nums[left]) {
				left = middle + 1;
			} else {
				right = middle;
			}
		}
		return nums[right];
    }
};
