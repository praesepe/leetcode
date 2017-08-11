#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
		mp = {
			{'2', "abc"},
			{'3', "def"},
			{'4', "ghi"},
			{'5', "jkl"},
			{'6', "mno"},
			{'7', "pqrs"},
			{'8', "tuv"},
			{'9', "wxyz"},
		};
	}

	vector<string> letterCombinations(string digits) {
		vector<string> result;

		if (digits.length() == 0) {
			return result;
		}

		int level = -1;
		queue<string> q;
		q.push("");

		while (!q.empty()) {
			int n = q.size();
			level++;

			for (int i = 0; i < n; i++) {
				string t = q.front();
				q.pop();

				if (t.length() == digits.length()) {
					result.push_back(t);
				}

				for (const auto ch: mp[digits[level]]) {
					q.push(t + ch);
				}
			}
		}

		return result;
    }
private:
	unordered_map<char, string> mp;
};

int main()
{
	string s = "23";

	Solution slt;
	slt.letterCombinations(s);

	return 0;
}
