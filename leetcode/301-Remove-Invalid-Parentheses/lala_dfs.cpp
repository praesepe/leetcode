#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

#define FOUND -1
#define REVERSE -2

class Solution {
private:
	int find_failed_position(string s, bool is_reversed) {
		char plus_char = !is_reversed ? '(' : ')';
		char minus_char = !is_reversed ? ')' : '(';
		int count = 0;
		// TODO: I think it can be optimized by offseting the starting index
		for (size_t i = 0; i < s.size(); i++) {
			if (s[i] == plus_char) {
				count++;
			} else if (s[i] == minus_char) {
				count--;
			}

			if (count < 0) return i;
		}

		return count == 0 ? FOUND : REVERSE;
	}

	void search_and_removed(string s, unordered_set<string>& answers, unordered_map<bool, unordered_set<string>>& visited, bool is_reversed) {
        if (visited[is_reversed].find(s) != visited[is_reversed].end()) return;

        visited[is_reversed].insert(s);
		char search_char = !is_reversed ? ')' : '(';
		int failed_position = this->find_failed_position(s, is_reversed);

		switch (failed_position) {
        case FOUND:
            if (is_reversed) reverse(s.begin(), s.end());
            if (answers.find(s) != answers.end()) return;
            answers.insert(s);
            break;
        case REVERSE:
            reverse(s.begin(), s.end());
            this->search_and_removed(s, answers, visited, !is_reversed);
            break;
        default:
            for (int i = 0; i <= failed_position; i++) {
                if (s[i] != search_char) continue;

                string removed_string = s.substr(0, i) + s.substr(i + 1);
                this->search_and_removed(removed_string, answers, visited, is_reversed);
            }
		}
	}
public:
	vector<string> removeInvalidParentheses(string s) {
		unordered_set<string> answers;
        unordered_map<bool, unordered_set<string>> visited = {{ true, {} }, { false, {} }};


		this->search_and_removed(s, answers, visited, false);

		return vector<string>(answers.begin(), answers.end());
	}
};

