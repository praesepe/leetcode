#include <string>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		string result(s.size(), NULL);

		int start_index = 0;
		for (size_t i = 0; i <= s.size(); i++) {
			if (s[i] != ' ' && i != s.size()) continue;

			// copy string
			int copy_begin = start_index;
			for (int j = i - 1 ; j >= copy_begin ; j--) {
				result[start_index++] = s[j];
			}

			if (i != s.size()) result[start_index++] = ' ';
		}

		return result;
	}
};
