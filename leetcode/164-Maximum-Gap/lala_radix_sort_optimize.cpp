#include <string.h>
#include <stdlib.h>
#include <list>
#include <vector>

using namespace std;

#define DEGREE 32
#define BUCKET_SIZE 2

class Solution {
private:
	int get_loop_count(const vector<int>& nums) {
		int max_num = *max_element(nums.begin(), nums.end());
		int loop_count;
		for (loop_count = 1; loop_count < DEGREE; loop_count++) {
			if (0 == (max_num >> loop_count)) break;
		}

		return loop_count;
	}

	void counting(int* count, const vector<int>& nums, int digit_index) {
		memset(count, 0, sizeof(*count) * BUCKET_SIZE);
		for (const auto num : nums) {
			int digit = (num >> digit_index) & 0x1;
			count[digit]++;
		}
		// accumulation
		count[1] += count[0];
	}

	void rolling(const vector<int>& src, vector<int>& dest, int count[], int digit_index) {
		for (int i = src.size() - 1; i >= 0; i--) {
			int num = src[i];
			int digit = (num >> digit_index) & 0x1;
			int index = count[digit] - 1;

			dest[index] = num;
			count[digit]--;
		}
	}
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() == 0) return 0;

		// find loop count
		int loop_count = this->get_loop_count(nums);

		// initialize rolling data
		vector<int> runs[2];
		for (int i = 0; i < 2; i++) runs[i].resize(nums.size());

		// run
		int count[BUCKET_SIZE];
		runs[0] = nums;
		for (int i = 0; i < loop_count; i++) {
			vector<int> &src = runs[i % 2];
			vector<int> &dest = runs[(i + 1) % 2];

			// counting
			this->counting(count, nums, i);

			// rolling
			this->rolling(src, dest, count, i);

		}

		// compute result
		vector<int> &target = runs[loop_count % 2];
		int result = INT_MIN;
		int previous = target[0];

		for (const auto num : target) {
			result = max(result, abs(num - previous));
			previous = num;
		}
		return result;
	}
};
