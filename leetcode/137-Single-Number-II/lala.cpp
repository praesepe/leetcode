class Solution {
private:
	static bool compare(int i, int j) {
		return i < j;
	}
public:
	int singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), Solution::compare);

		int result = 0;
		for (int i = 0; i < 32; i++) {
			for (int i = 0; i < nums.size(); i += 3) {
				if (nums[i] != nums[i + 1] && nums[i] != nums[i + 2]) {
					return nums[i];
				}
			}
		}

		return nums[nums.size() - 1];
	}
};
