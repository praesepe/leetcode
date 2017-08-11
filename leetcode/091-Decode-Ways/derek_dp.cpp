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

		// dp[i] = dp[i-1] + dp[i-2]

		vector<int> dp(s.length(), 0);
		int n;

		// dp[0]
		dp[0] = (s[0] == '0') ? 0 : 1;

		// dp[1]
		if (s[1] != '0') {
			dp[1] += dp[0];
		}
		n = stoi(s.substr(0, 2));
		if (10 <= n && n <=26) {
			dp[1] += 1;
		}

		for (int i = 2; i < s.length(); i++) {
			// dp[i-1]
			if (s[i] != '0') {
				dp[i] += dp[i-1];
			}

			// dp[i-2]
			n = stoi(s.substr(i-1, 2));
			if (10 <= n && n <=26) {
				dp[i] += dp[i-2];
			}
		}

		return dp[s.length()-1];
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
