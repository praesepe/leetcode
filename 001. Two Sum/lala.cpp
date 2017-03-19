class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;

		// initialize lookup table
		unordered_map<int, int> um;
		for (vector<int>::size_type i = 0; i < nums.size(); i++) {
			um.insert(pair<int, int>(nums[i], i));
		}

		// main
		for (vector<int>::size_type i = 0; i < nums.size(); i++) {
			int lookup_target = target - nums[i];
			unordered_map<int, int>::iterator itr = um.find(lookup_target);
			if (itr != um.end() && itr->second != i) {
				result.push_back(i);
				result.push_back(itr->second);
				break;
			}
		}

		return result;
	}
};
