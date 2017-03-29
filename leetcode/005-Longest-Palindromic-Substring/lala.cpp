#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		bool table[1000][1000];
		memset(table, 0, sizeof(table));

		int maxLength = 0;
		int maxI = 0;
		int maxJ = 0;
		for (int diff = 0; diff < s.size(); diff++) {
			for (int j = s.size() - 1; j >= diff; j--) {
				int i = j - diff;

				if (i == j) {
					table[i][j] = true;
				} else if (j - i == 1 && s[i] == s[j]) {
					table[i][j] = true;
				} else if (i < j) {
					table[i][j] = s[i] == s[j] && table[i + 1][j - 1];
				}

				int subLength = j - i + 1;
				if (table[i][j] && maxLength < subLength) {
					maxI = i;
					maxJ = j;
					maxLength = subLength;
				}
			}
		}

		// table results
		/*
		   for (int i = 0; i < s.size(); i++) {
		   for (int j = 0; j < s.size(); j++) {
		   cout << table[i][j] << " ";
		   }
		   cout << endl;
		   }
		   */

		return s.substr(maxI, maxLength);
	}
};
