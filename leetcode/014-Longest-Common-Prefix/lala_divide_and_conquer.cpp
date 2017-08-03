#include <string>
#include <vector>

using namespace std;
class Solution {
private:
	// T(N) = 2T(N/2) + O(M)
	string find_longest_common_string(vector<string>& strs, int left, int right) {
		if (left == right) return strs[left];

		int middle = (uint64_t(left + right) >> 1);
		string left_common_string = this->find_longest_common_string(strs, left, middle);
		string right_common_string = this->find_longest_common_string(strs, middle + 1, right);

		return this->common_prefix(left_common_string, right_common_string);
	}

	string common_prefix(string s1, string s2) {
		size_t length = min(s1.size(), s2.size());

		size_t index;
		for (index = 0; index < length; index++) {
			if (s1[index] != s2[index]) break;
		}

		return s1.substr(0, index);
	}
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";

		return this->find_longest_common_string(strs, 0, strs.size() - 1);
	}
};
