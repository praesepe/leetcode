#include <cmath>

using namespace std;

class Solution {
private:
	int loopCount(int x) {
		int count = 0;
		for (int i = 0; x != 0; i++) {
			x /= 10;
			count++;
		}

		return count;
	}
public:
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}

		// find count
		int count = this->loopCount(x);

		// main
		for (int i = 0; i < count / 2; i++) {
			int head = (int) (x / pow(10, count - i - 1)) % 10;
			int tail = (int) (x / pow(10, i)) % 10;
			if (head != tail) {
				return false;
			}
		}

		return true;
	}
};
