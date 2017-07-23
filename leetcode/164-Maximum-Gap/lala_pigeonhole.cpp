#include <vector>
#include <algorithm>

using namespace std;
struct Bucket {
	int min;
	int max;
	bool is_empty;
	Bucket() : min(INT_MAX), max(INT_MIN), is_empty(true) {};
};

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) return 0;

		int maxValue = *max_element(nums.begin(), nums.end());
		int minValue = *min_element(nums.begin(), nums.end());
		int interval = max(1, int((maxValue - minValue) / (nums.size() + 1)));

		// setup buckets
		vector<Bucket> buckets(((maxValue - minValue) / interval) + 1) ;
		for (const auto num : nums) {
			int index = (num - minValue) / interval;
			buckets[index].is_empty = false;
			buckets[index].min = min(buckets[index].min, num);
			buckets[index].max = max(buckets[index].max, num);
		}

		// run
		int result = 0;
		int previousMax = minValue;
		for (const auto bucket : buckets) {
			if (bucket.is_empty) continue;

			result = max(result, bucket.min - previousMax);
			previousMax = bucket.max;
		}

		return result;
	}
};
