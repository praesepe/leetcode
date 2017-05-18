#include <list>
#include <vector>

using namespace std;

#define DEGREE 8
#define BUCKET_SIZE 16
#define SHIFT_AMOUNT 4

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		// init bucket
		list<int> buckets[DEGREE][BUCKET_SIZE];
		for (size_t i = 0; i < nums.size(); i++) {
			int digit = nums[i] & 0x0f;
			buckets[0][digit].push_back(nums[i]);
		}

		// run buckets
		for (int i = 1; i < DEGREE; i++) {
			for (int j = 0; j < BUCKET_SIZE; j++) {
				for (const auto num : buckets[i - 1][j]) {
					int digit = (num >> (i * SHIFT_AMOUNT)) & 0x0f;
					buckets[i][digit].push_back(num);
				}
			}
		}

		// compute result
		int result = 0;
		int previous_target = INT_MAX;
		for (int i = 0; i < BUCKET_SIZE; i++) {
			for (const auto target : buckets[DEGREE - 1][i]) {
				result = max(result, target - previous_target);
				previous_target = target;
			}
		}

		return result;
	}
};
