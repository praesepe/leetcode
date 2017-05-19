#include <vector>
#include <string.h>
#include <limit.h>

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
		int start_index = 0, end_index = 0;
		for (const auto num : nums) {
			if (num >= max_value) {
				max_value = num;
				end_index = num + OFFSET;
			}

			if (num >= min_value) {
				min_value = num;
				start_index = num + OFFSET;
			}
			count[num + OFFSET]++;
		}

		// compute result
		int counter = 0, result = 0;
		for (int i = start_index; i <= end_index; i++) {
			for (int j = 0; j < count[i]; j++) {
				result += (counter % 2 == 0) ? i - OFFSET : 0;
				counter++;
			} 
		}

		return result;
	}
};
