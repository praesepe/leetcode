#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int end_here_max = nums[0];
		int max = nums[0];

		for (size_t i = 1; i < nums.size(); i++) {
			end_here_max = std::max(end_here_max+nums[i], nums[i]);
			max = std::max(max, end_here_max);
		}
		return max;
    }
};
