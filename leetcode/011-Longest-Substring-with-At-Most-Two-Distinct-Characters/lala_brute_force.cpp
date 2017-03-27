#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

#define MOST_OCCURRENCE 2
using namespace std;
class Solution {
public:
	static string solve(string s) {
		string result = "", tmp = "";
		string::size_type i, j;

		for (i = 0; i < s.size(); i++) {
			unordered_set<char> us;
			for (j = i; j < s.size(); j++) {
				us.insert(s[j]);

				if (us.size() > MOST_OCCURRENCE) {
					j--;
					break;
				}
			}

			tmp = s.substr(i, j - i + 1);
			result = result.size() > tmp.size() ? result : tmp;
		}

		return result;
	}
};

int main() {
	vector<string> testcases;
	testcases.push_back("eceba");
	testcases.push_back("aaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaa");
	testcases.push_back("abbcccdddd");
	testcases.push_back("abbcccbbbbdddddbbbbbb");
	testcases.push_back("abababababababababababcccccccccccccccccccccccccccccccccccccdd");

	for (vector<string>::size_type i = 0; i < testcases.size(); i++) {
		string testcase = testcases[i];
		string result = Solution::solve(testcase);

		cout << testcase << ": " << result << " <" << result.size() << ">" << endl;
	}
	return 0;
}
