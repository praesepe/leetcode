#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<int> arr;
		sort(nums.begin(), nums.end());
		dfs(nums, 0, arr, 0);
		return answer;
    }

	void dfs(vector<int>& nums, int pos, vector<int> arr, int sum) {
		if (arr.size() == 3) {
			if (sum == 0) {
				// check visit
				string key;
				for (int i = 0; i < arr.size(); i++) {
					key += to_string(arr[i]) + "_";
				}
				if (visit.find(key) == visit.end()) {
					visit[key] = 1;
					answer.push_back(arr);
				}
			}
			return;
		}

		if (pos == nums.size()) {
			return;
		}

		// don't pick this num
		dfs(nums, pos+1, arr, sum);
		// pick this num
		arr.push_back(nums[pos]);
		sum += nums[pos];
		dfs(nums, pos+1, arr, sum);
	}

private:
	map<string, int> visit;
	vector<vector<int>> answer;
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
