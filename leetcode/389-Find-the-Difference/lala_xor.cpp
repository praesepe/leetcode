#include <string>

using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		char result = 0;
		for (size_t i = 0; i < s.size(); i++) {
			result ^= s[i];
		}

		for (size_t i = 0; i < t.size(); i++) {
			result ^= t[i];
		}

		return result;
	}
};
