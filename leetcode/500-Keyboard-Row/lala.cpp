#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
	int get_line(char target) {
		return this->_lines[target];
	}
public:
	Solution() {
		const char* lines[] = {
			"qwertyuiop",
			"asdfghjkl",
			"zxcvbnm",
			NULL
		};

		for (size_t i = 0; lines[i] != NULL; i++) {
			for (size_t j = 0; lines[i][j] != '\0'; j++) {
				this->_lines[lines[i][j]] = i;
				this->_lines[lines[i][j] - 32] = i;
			}
		}
	}

	vector<string> findWords(vector<string>& words) {
		vector<string> result;

		for (const auto word : words) {
			bool same_row = true;
			int line = this->get_line(word[0]);
			for (size_t i = 1; i < word[i];i++) {
				if (line != this->get_line(word[i])) {
					same_row = false;
					break;
				}
			}

			if (same_row) result.push_back(word);
		}

		return result;
	}
private:
	unordered_map<char, int> _lines;
};
