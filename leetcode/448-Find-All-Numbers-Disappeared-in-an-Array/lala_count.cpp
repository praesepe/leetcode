#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int N = nums.size() + 1;
		int* count = new int[N];
		memset(count, 0, sizeof(int) * N);

		for (const auto num : nums) {
			count[num]++;
		}

		vector<int> result;
		for (size_t i = 1; i < N; i++) {
			if (count[i] == 0) result.push_back(i);
		}

		delete [] count;
		return result;
	}
};
