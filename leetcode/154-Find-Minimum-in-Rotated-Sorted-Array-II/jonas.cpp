class Solution {
public:
    int findMin(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int min = INT_MAX;

		while (left <= right) {
			if (nums[left] < nums[right]) {
				min = std::min(nums[left], min);
				break;
			}

			int middle = (left + right) / 2;
			min = std::min(nums[middle], min);

			if (nums[middle] < nums[right]) {
				right = middle - 1;
			} else if (nums[middle] > nums[left]) {
				left = middle + 1;
			} else {
				left++;
			}
		}
		return min;
    }
};
