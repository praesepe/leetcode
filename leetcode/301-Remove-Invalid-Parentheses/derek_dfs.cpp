#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
		vector<string> result;
		dfs(s, 0, 0, '(', ')', result);
		return result;
    }

	void dfs(string s, int last_i, int last_j, char left_per, char right_per, vector<string>& result)
	{
		int count = 0;
		for (int i = last_i; i < s.length(); i++) {
			// Find which new character make the string invalid. We use a counter
			// to detect invalid string.
			if (s[i] == left_per) {
				count++;
			}
			if (s[i] == right_per) {
				count--;
			}
			if (count >= 0) {
				continue;
			}

			// Remove one of right parentheses
			for (int j = last_j; j <= i; j++) {
				// 'j == last_j' means the first right parentheses from the last time
				// 's[j-1] != right_per' means we only choose the first parentheses in a continous right parentheses
				if (s[j] == right_per && (j == last_j || s[j-1] != right_per)) {
					string t = s.substr(0, j) + s.substr(j+1);
					dfs(t, i, j, left_per, right_per, result);
				}
			}
			return;
		}

		reverse(s.begin(), s.end());

		// only allow leagal string to check reverse order
		if (left_per == '(') {
			dfs(s, 0, 0, ')', '(', result);
		} else {
			result.push_back(s);
		}
	}
};

int main()
{
	vector<string> s = {
		"()())()",
		"(a)())()",
		")("
	};

	Solution slt;
	for (int i = 0; i < s.size(); i++) {
		// input
		printf("%s -> ", s[i].c_str());

		//
		vector<string> r = slt.removeInvalidParentheses(s[i]);

		// output
		printf("[");
		for (int j = 0; j < r.size(); j++) {
			printf("%s", r[j].c_str());
			if (j != r.size()-1) {
				printf(", ");
			}
		}
		printf("]\n");
	}

	return 0;
}
