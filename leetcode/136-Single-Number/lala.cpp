class Solution {
private:
	static bool compare(int i, int j) {
		return i < j;
	}
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;

		for (int i = 0; i < nums.size(); i++) {
			result = result ^ nums[i];
		}

		return result;
	}
};
