#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> answer;
		sort(nums.begin(), nums.end());

		int left, right, sum;
		for (int i = 0; i + 2 < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i-1]) {
				continue;
			}

			left = i + 1;
			right = nums.size() - 1;

			while (left < right) {
				sum = nums[i] + nums[left] + nums[right];
				if (sum == 0) {
					answer.push_back({nums[i], nums[left], nums[right]});
				}
				if (sum <= 0) {
					while (left < right) {
						left++;
						if (nums[left] != nums[left-1]) {
							break;
						}
					};
				}
				if (sum >= 0) {
					while (left < right) {
						right--;
						if (nums[right] != nums[right+1]) {
							break;
						}
					};
				}
			}
		}

		return answer;
    }
};

int main()
{
	vector<int> nums = {-1, 0, 1, 2, -1, -4};

	Solution slt;
	vector<vector<int>> ans = slt.threeSum(nums);

	for (int i = 0; i < ans.size(); i++) {
		printf("%d, %d, %d\n", ans[i][0], ans[i][1], ans[i][2]);
	}

	return 0;
}
