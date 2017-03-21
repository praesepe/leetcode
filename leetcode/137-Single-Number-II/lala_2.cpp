#define NTHBIT(v, shift) ((v >> shift) & 0x1)
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;

		for (int i = 0; i < 32; i++) {
			int sum = 0;

			for (int j = 0; j < nums.size(); j++) {
				sum += NTHBIT(nums[j], i);
			}

			// setbit
			result = result | ((sum % 3) << i);
		}

		return result;
	}
};
