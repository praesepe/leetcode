#include <stdint.h>
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int left = 1, right = n;

		while (right > left) {
			int mid = ((uint32_t) left + (uint32_t) right) >> 1;
			switch (guess(mid)) {
			case -1:
				right = mid - 1;
				break;
			case 1:
				left = mid + 1;
				break;
			case 0:
				return mid;
			}
		}

		return right;
	}
};
