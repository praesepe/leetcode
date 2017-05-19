#include <cstring>

using namespace std;

class Solution {
private:
	void create_table() {
		memset(this->lookup_table, 0, sizeof(this->lookup_table));
		for (int i = 0; i < 256; i++) {
			this->lookup_table[i] = (i & 0x1) + lookup_table[i >> 1];
		}
	}
public:
	Solution() {
		this->create_table();
	}

	int hammingDistance(int x, int y) {
		int target = x ^ y;

		return this->lookup_table[target & 0xff] +
			this->lookup_table[(target >> 8) & 0xff] +
			this->lookup_table[(target >> 16) & 0xff] +
			this->lookup_table[(target >> 24) & 0xff];
	}
private:
	int lookup_table[256];
};
