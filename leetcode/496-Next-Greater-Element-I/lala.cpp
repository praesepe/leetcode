#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		stack<int> compute;
		unordered_map<int, int> next_greater;

		// compute
		for (int i = nums.size() - 1 ; i >= 0; i--) {
			int num = nums[i];
			while (!compute.empty()) {
				if (compute.top() > num) break;
				compute.pop();
			}

			next_greater[num] = compute.empty() ? -1 : compute.top();
			compute.push(num);
		}

		// result
		vector<int> result;
		for (const auto num : findNums) {
			result.push_back(next_greater[num]);
		}

		return result;
	}
};
