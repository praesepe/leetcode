#include <string.h>

#define MAX_SIZE 731

class Solution {
private:
	int compute_square_sum(int target) {
		int result = 0;
		while (target) {
			int digit = target % 10;
			result += digit * digit;
			target /= 10;
		}

		return result;
	}
public:
	bool isHappy(int n) {
		bool visits[MAX_SIZE];
		memset(visits, 0, sizeof(visits));

		int target = this->compute_square_sum(n);
		while (true) {
			if (target == 1) return true;
			if (visits[target]) return false;

			visits[target] = true;
			target = this->compute_square_sum(target);
		}
	}
};
