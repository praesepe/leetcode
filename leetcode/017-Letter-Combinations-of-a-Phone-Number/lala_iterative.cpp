#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

struct StackNode {
	int offset;
	string current;

	StackNode(int offset, string current) {
		this->offset = offset;
		this->current = current;
	}
};

class Solution {
public:
	Solution() {
		this->_digits_mapping = {
			{'2', "abc"},
			{'3', "def"},
			{'4', "ghi"},
			{'5', "jkl"},
			{'6', "mno"},
			{'7', "pqrs"},
			{'8', "tuv"},
			{'9', "wxyz"}
		};
	}

	vector<string> letterCombinations(string digits) {
		vector<string> answer;
		if (digits.size() == 0) return {};


		stack<StackNode> s;
		s.push(StackNode(0, ""));
		while (!s.empty()) {
			StackNode sn = s.top();
			s.pop();
			if (sn.offset == digits.size()) {
				answer.push_back(sn.current);
				continue;
			}

			for (const auto letter : this->_digits_mapping[digits[sn.offset]]) {
				s.push(StackNode(sn.offset + 1, sn.current + letter));
			}
		}

		return answer;
	}
private:
	unordered_map<char, string> _digits_mapping;
};
