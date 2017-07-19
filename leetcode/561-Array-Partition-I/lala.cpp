#include <vector>
#include <string.h>
#include <limits.h>

using namespace std;

#define OFFSET 10000
#define MAX_SIZE 20001

class Solution {
public:
int arrayPairSum(vector<int>& nums) {
	int count[MAX_SIZE];
	memset(count, 0, sizeof(count));

	// sorting
	int max_value = INT_MIN, min_value = INT_MAX;
	for (const auto num : nums) {
		if (num >= max_value) max_value = num;            
		if (num <= min_value) min_value = num;

		count[num + OFFSET]++;
	}

	// compute result
	int result = 0, remain = 0, previous_value = 0;
	int start_index = min_value + OFFSET, end_index = max_value + OFFSET;
	for (int i = start_index; i <= end_index; i++) {
		if (count[i] == 0) continue;

		int total_count = count[i] - remain;
		int times = total_count / 2;
		int value = i - OFFSET;

		result += (value * times) + previous_value;
		remain = total_count % 2;
		previous_value = remain == 1 ? value : 0;
	}

	return result;
}
};
