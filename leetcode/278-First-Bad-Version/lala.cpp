#include <stdint.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		uint64_t left = 0;
		uint64_t right = n;

		int result = 0;
		while (right >= left) {
			uint64_t mid = (left + right) / 2;
			if (isBadVersion(mid)) {
				right = mid - 1;
				result = mid;
			} else {
				left = mid + 1;
			}
		}

		return result;
	}
};
