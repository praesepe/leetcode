#include <vector>
using namespace std;

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int sum = 0;
		int min_num = INT_MAX;
		for (const auto num : nums) {
			sum += num;
			min_num = min(min_num, num);
		}

		return sum - min_num * nums.size();
	}
};
