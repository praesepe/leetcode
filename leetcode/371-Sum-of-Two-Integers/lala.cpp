#include <stdio.h>
class Solution {
public:
	int getSum(int a, int b) {
		int result = 0;
		int carry = 0;
		for (int i = 0; i < 32; i++) {
			int lsb_a = (a >> i) & 1;
			int lsb_b = (b >> i) & 1;

			result = result | ((lsb_a ^ lsb_b ^ carry) << i);
			carry = (lsb_a & lsb_b) | (lsb_a & carry) | (lsb_b & carry);
		}

		return result;
	}
};
