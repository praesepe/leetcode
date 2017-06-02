#include <vector>

using namespace std;
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int N = nums.size() + 1;
		int* count = new int[N];
		memset(count, 0, sizeof(int) * N);

		// mark visted number to the negative value
		for (const auto num : nums) {
			int index = (num < 0 ? -num : num) - 1;
			nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
		}

		// compute result
		vector<int> result;
		for (size_t i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) result.push_back(i + 1);
		}

		return result;
	}
};
