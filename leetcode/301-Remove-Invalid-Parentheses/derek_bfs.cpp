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

		int found = false;
		map<string, int> visited;
		queue<string> q;
		q.push(s);
		while (!q.empty()) {
			s = q.front();
			q.pop();

			if (isValid(s)) {
				result.push_back(s);
				found = true;
			}

			if (found) {
				continue;
			}

			for (int i = 0; i < s.length(); i++) {
				if (s[i] == '(' || s[i] == ')') {
					string t = s.substr(0, i) + s.substr(i + 1);
					if (visited.find(t) == visited.end()) {
						q.push(t);
						visited[t]++;
					}
				}
			}
		}

		return result;
    }

	bool isValid(string s)
	{
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				count++;
			}
			if (s[i] == ')') {
				count--;
			}
			if (count < 0) {
				return false;
			}
		}
		return count == 0;
	}
};

int main()
{
	string s1 = "()())()";

	///Solution slt;
	//vector<string> result = slt.removeInvalidParentheses(s1);


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


// ()())() -> ["()()()", "(())()"]
