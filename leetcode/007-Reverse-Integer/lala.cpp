#include <limits.h>

class Solution {
public:
	int reverse(int x) {
		int result = 0;

		int num = x;
		while (num != 0) {
			// head
			int tmp = result * 10;
			if (tmp / 10 != result) {
				result = 0;
				break;
			}
			result = tmp;

			// tail
			tmp = num % 10;
			if ((x > 0 && x > INT_MAX - tmp) || (x < 0 && x < INT_MIN - tmp)) {
				result = 0;
				break;
			}
			result += tmp;

			// shift
			num /= 10;
		}

		return result;
	}
};
