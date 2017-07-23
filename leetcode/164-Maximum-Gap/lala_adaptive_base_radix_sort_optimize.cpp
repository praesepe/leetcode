#include <string.h>
#include <stdlib.h>
#include <list>
#include <math.h>
#include <vector>

using namespace std;

#define DEGREE 32
#define MASK(x) ((0x1LL << (x)) - 1)
#define BUCKET_SIZE(x) (1 << (x))

class Solution {
private:
	int get_loop_count(const vector<int>& nums, int base) {
		int max_num = *max_element(nums.begin(), nums.end());
		int loop_count;
		int shift = 1;
		for (loop_count = 1; loop_count < DEGREE / base; loop_count++) {
			if (0 == (max_num >> shift)) break;
			shift += base;
		}

		return loop_count;
	}

	void counting(int* count, int count_size, const vector<int>& nums, int shift, int mask) {
		memset(count, 0, sizeof(*count) * count_size);
		for (const auto num : nums) {
			int digit = (num >> shift) & mask;
			count[digit]++;
		}
		// accumulation
		int accumulation = count[0];
		for (int i = 1; i < count_size; i++) {
			count[i] += accumulation;
			accumulation = count[i];
		}
	}

	void rolling(const vector<int>& src, vector<int>& dest, int* count, int shift, int mask) {
		for (int i = src.size() - 1; i >= 0; i--) {
			int num = src[i];
			int digit = (num >> shift) & mask;
			int index = count[digit] - 1;

			if (index == -1) continue;
			dest[index] = num;
			count[digit]--;
		}
	}

	vector<int> radix_sort(vector<int>& nums, int base) {
		// find loop count
		int loop_count = this->get_loop_count(nums, base);

		// initialize rolling data
		vector<int> runs[2];
		for (int i = 0; i < 2; i++) runs[i].resize(nums.size());

		// run
		int count_size = BUCKET_SIZE(base);
		int mask = MASK(base);
		int *count = new int[count_size];

		runs[0] = nums;
		for (int i = 0; i < loop_count; i++) {
			vector<int> &src = runs[i & 0x1];
			vector<int> &dest = runs[(i + 1) & 0x1];
			int shift = i * base;

			// counting
			this->counting(count, count_size, nums, shift, mask);

			// rolling
			this->rolling(src, dest, count, shift, mask);
		}

		delete [] count;

		// compute result
		return runs[loop_count & 0x1];
	}
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() == 0) return 0;

		// choose base
		int base = ceil(log2(sqrt(nums.size())));

		// sorting
		vector<int> sorted = radix_sort(nums, base == 0 ? 1 : base);

		// compute result
		int result = INT_MIN;
		int previous = sorted[0];

		for (const auto num : sorted) {
			result = max(result, abs(num - previous));
			previous = num;
		}

		return result;
	}
};
