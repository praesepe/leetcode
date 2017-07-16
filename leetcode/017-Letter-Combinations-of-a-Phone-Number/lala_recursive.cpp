#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

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
			{'9', "wxyz"},
		};
	}

	void combine(vector<string> &answer, string digits, string current, size_t start) {
		if (digits.size() == current.size()) {
			answer.push_back(current);
			return;
		}

		for (size_t i = start; i < digits.size(); i++) {
			for (const auto letter : this->_digits_mapping[digits[i]]) {
				combine(answer, digits, current + letter, i + 1);
			}
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> answer;

		if (digits.size() > 0) this->combine(answer, digits, "", 0);

		return answer;
	}
private:
	unordered_map<char, string> _digits_mapping;
};
