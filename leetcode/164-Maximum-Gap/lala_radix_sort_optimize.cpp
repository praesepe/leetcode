#include <string.h>
#include <stdlib.h>
#include <list>
#include <vector>

using namespace std;
#define DEGREE 32
// RADIX BASE: 2^BITS_BASE
#define BITS_BASE 3
#define MASK ((0x1LL << BITS_BASE) - 1)
#define BUCKET_SIZE (1 << BITS_BASE)


class Solution {
private:
	int get_loop_count(const vector<int>& nums) {
		int max_num = *max_element(nums.begin(), nums.end());
		int loop_count;
		int shift = 1;
		for (loop_count = 1; loop_count < DEGREE / BITS_BASE; loop_count++) {
			if (0 == (max_num >> shift)) break;
			shift += BITS_BASE;
		}

		return loop_count;
	}

	void counting(int* count, const vector<int>& nums, int shift) {
		memset(count, 0, sizeof(*count) * BUCKET_SIZE);
		for (const auto num : nums) {
			int digit = (num >> shift) & MASK;
			count[digit]++;
		}
		// accumulation
		int accumulation = count[0];
		for (int i = 1; i < BUCKET_SIZE; i++) {
			count[i] += accumulation;
			accumulation = count[i];
		}
	}

	void rolling(const vector<int>& src, vector<int>& dest, int count[], int shift) {
		for (int i = src.size() - 1; i >= 0; i--) {
			int num = src[i];
			int digit = (num >> shift) & MASK;
			int index = count[digit] - 1;

			if (index == -1) continue;
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
			vector<int> &src = runs[i & 0x1];
			vector<int> &dest = runs[(i + 1) & 0x1];
			int shift = i * BITS_BASE;

			// counting
			this->counting(count, nums, shift);

			// rolling
			this->rolling(src, dest, count, shift);
		}

		// compute result
		vector<int> &target = runs[loop_count & 0x1];
		int result = INT_MIN;
		int previous = target[0];

		for (const auto num : target) {
			result = max(result, abs(num - previous));
			previous = num;
		}
		return result;
	}
};
