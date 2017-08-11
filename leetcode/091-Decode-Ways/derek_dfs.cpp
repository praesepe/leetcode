#include <cstdio>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
		if (s.empty()) {
			return 0;
		}

		int lenS = s.length();
		int count = 0;
		int n;

		queue<string> q;
		q.push("");

		while (!q.empty()) {
			string t = q.front();
			q.pop();

			// the string contains whole s string
			int lenT = t.length();
			if (lenT == lenS) {
				count++;
				continue;
			}

			// add 1 characters
			if ((lenS - lenT) >= 1) {
				n = stoi(s.substr(lenT, 1));
				if (1 <= n && n <= 9) {
					q.push(s.substr(0, lenT + 1));
				}
			}

			// add 2 characters
			if ((lenS - lenT) >= 2) {
				n = stoi(s.substr(lenT, 2));
				if (10 <= n && n <= 26) {
					q.push(s.substr(0, lenT + 2));
				}
			}
		}

		return count;
    }
};

int main()
{
	string s = "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948";

	Solution slt;
	int count = slt.numDecodings(s);
	cout << count << endl;

	return 0;
}
