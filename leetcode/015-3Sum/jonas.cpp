class Solution {
 public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::vector<std::vector<int>> ans;
		std::sort(nums.begin(), nums.end());

		for (int i = 0; i + 2 < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i-1]) {
				continue;
			}

			for (int l = i + 1, r = nums.size() - 1; l < r; ) {
				int sum = nums[i] + nums[l] + nums[r];

				if (sum == 0) {
					ans.push_back({nums[i], nums[l], nums[r]});
				}
				if (sum <= 0) {
					while (l < r && nums[l++] == nums[l]) {}
				}
				if (sum >= 0) {
					while (l < r && nums[r--] == nums[r]) {}
				}
			}
		}
		return ans;
    }
};
