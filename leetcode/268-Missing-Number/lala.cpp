#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
private:
	int originalSum(int n) {
		return n * (0 + n - 1) / 2;
	}
public:
	int missingNumber(vector<int>& nums) {
		int sum = 0;
		for (const auto num : nums) {
			sum += num;
		}

		return this->originalSum(nums.size() + 1) - sum;
	}
};
