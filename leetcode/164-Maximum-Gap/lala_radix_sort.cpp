#include <list>
#include <vector>

using namespace std;

#define DEGREE 32
#define BUCKET_SIZE 2

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		// init bucket
		list<int> buckets[DEGREE][BUCKET_SIZE];
		int max_mum = INT_MIN;
		for (size_t i = 0; i < nums.size(); i++) {
			int digit = nums[i] & 0x1;
			buckets[0][digit].push_back(nums[i]);
			max_mum = max(max_mum, nums[i]);
		}

		// find loop size
		int loop_size = 1;
		for (loop_size = 1; loop_size < DEGREE ; loop_size++) {
			if (0 == (max_mum >> loop_size)) {
				break;
			}
		}

		// run buckets
		for (int i = 1; i < loop_size; i++) {
			for (int j = 0; j < BUCKET_SIZE; j++) {
				for (const auto num : buckets[i - 1][j]) {
					int digit = (num >> i) & 0x1;
					buckets[i][digit].push_back(num);
				}
			}
		}

		// compute result
		int result = 0;
		int previous_target = INT_MAX;
		for (int i = 0; i < BUCKET_SIZE; i++) {
			for (const auto target : buckets[loop_size - 1][i]) {
				result = max(result, target - previous_target);
				previous_target = target;
			}
		}

		return result;
	}
};
