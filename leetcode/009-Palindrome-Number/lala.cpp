#include <cmath>
#define MAPPING_SIZE 10
using namespace std;

class Solution {
private:
	int loopCount(int x) {
		int left = 0;
		int right = MAPPING_SIZE - 1;

		while (right > left) {
			int middle = (right + left) / 2;
			if (this->power_mapping[middle] > x) {
				right = middle - 1;
			} else if (this->power_mapping[middle] < x) {
				left = middle + 1;
			} else {
				return middle;
			}
		}

		return x / this->power_mapping[left] > 0 ? left : left - 1;
	}
public:
	Solution() {
		int power = 1;
		for (size_t i = 0; i < MAPPING_SIZE; i++) {
			power_mapping[i] = power;
			power = power * 10;
		}
	}

	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}

		// find count
		int count = this->loopCount(x);

		// main
		for (int i = 0; i < (count + 1 / 2); i++) {
			int head = (int) (x / this->power_mapping[count - i]) % 10;
			int tail = (int) (x / this->power_mapping[i]) % 10;
			if (head != tail) {
				return false;
			}
		}

		return true;
	}
private:
	int power_mapping[MAPPING_SIZE];
};
