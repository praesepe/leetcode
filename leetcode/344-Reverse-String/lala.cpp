#include <string>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		size_t half_size = s.size() / 2;
		for (size_t i = 0; i < half_size; i++) {
			swap(s[i], s[s.size() - i - 1]);
		}

		return s;
	}
};
