#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";

		// find miminum length
		size_t length = INT_MAX;
		for (auto const str : strs) {
			length = min(length, str.size());
		}

		// run
		string result = "";
		for (size_t j = 0; j < length; j++) {
			char target = strs[0][j];
			for (size_t i = 1; i < strs.size(); i++) {
				if (target != strs[i][j]) return result;
			}

			result += target;
		}

		return result;
	}
};
