#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.empty()) {
			return {1};
		}

		vector<int> result(digits.size());
		result[0] = 1;
		for (int i = digits.size() - 1; i >= 0; i--) {
			int resultIndex = digits.size() - 1 - i;
			int num = digits[i] + result[resultIndex];
			result[resultIndex] = (digits[i] + result[resultIndex]) % 10;

			num /= 10;
			for (int j = 1; num != 0; j++) {
				if (resultIndex + j >= result.size()) {
					result.resize(resultIndex + j + 1, 0);
				}
				result[resultIndex + j] += num % 10;
				num /= 10;
			}
		}

		reverse(result.begin(), result.end());
		return result;
	}
};
