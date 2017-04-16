#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> um = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000},
		};

		int lastValue = 0;
		int result = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			int current = um[s[i]];
			result += current < lastValue ?
				-1 * current : current;
			lastValue = current;
		}
		return result;
	}
};
