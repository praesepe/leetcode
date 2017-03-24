class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		// create lookup table
		map<int, int> mp;
		for (int i = 0; i < nums.size(); i++) {
			mp[nums[i]] = i;
		}

		// find complement
		for (int i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			if (mp.find(complement ) != mp.end() && mp[complement ] != i) {
				vector<int> result = {i, mp[complement]};
				return result;
			}
		}
	}
};
