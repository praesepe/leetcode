#include <stdint.h>

class Solution {
private:
	uint32_t find_msb_pos(int x) {
		uint32_t pos = 0;

		if (x & 0xffff0000) { pos += 16; x >>= 16; }
		if (x & 0x0000ff00) { pos += 8;  x >>= 8; }
		if (x & 0x000000f0) { pos += 4;  x >>= 4; }
		if (x & 0x0000000c) { pos += 2;  x >>= 2; }
		if (x & 0x00000003) { pos += 1;  x >>= 1; }

		return pos + (x & 0x1);
	}
public:
	int findComplement(int num) {
		int shift = 32 - this->find_msb_pos(num);

		return (((~num) << shift) >> shift);
	}
};
