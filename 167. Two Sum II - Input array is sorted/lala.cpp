class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result = {};

		int head = 0;
		int tail = nums.size() - 1;
		while (tail > head) {
			int head_target = nums[head];
			int tail_target = nums[tail];

			if (head_target + tail_target > target) {
				tail--;
			} else if (head_target + tail_target < target) {
				head++;
			} else if (head_target + tail_target == target) {
				result.push_back(head + 1);
				result.push_back(tail + 1);
				break;
			}
		}

		return result;
	}
};
