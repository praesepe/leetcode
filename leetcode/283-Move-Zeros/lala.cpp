#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		// swap
		size_t headIndex = 0;

		// head
		for (size_t i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) continue;

			if (i != headIndex) swap(nums[i], nums[headIndex]);
			headIndex++;
		}

		// fill zeros
		for (size_t i = headIndex; i < nums.size(); i++) {
			nums[i] = 0;
		}
	}
};
