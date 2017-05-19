#include <stdint.h>

class Solution {
public:
	int hammingDistance(int x, int y) {
		uint32_t i = x ^ y;
		uint32_t j = (i >> 1) & 0x55555555;
		i = i - j;
		i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
		i = (i & 0x0f0f0f0f) + ((i >> 4) & 0x0f0f0f0f);
		i = i * 0x01010101;

		return i >> 24;
	}
};
