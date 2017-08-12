#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

#define FOUND -1
#define REVERSE -2

struct SearchNode {
	string s;
	bool reversed;

	SearchNode(string s, bool reversed) {
		this->s = s;
		this->reversed = reversed;
	}
};

class Solution {
private:
	bool next(string s, bool reversed) {
		// check visited
		if (this->_visited[reversed].find(s) !=
			this->_visited[reversed].end()) {
			return false;
		}

		// search child
		this->_visited[reversed].insert(s);
		this->_search_stack.push(SearchNode(s, reversed));

		return true;
	}

	int find_failed_position(string s, bool is_reversed) {
		char plus_char = !is_reversed ? '(' : ')';
		char minus_char = !is_reversed ? ')' : '(';
		int count = 0;

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

	void dfs() {
		while (!this->_search_stack.empty()) {
			SearchNode sn = this->_search_stack.top();
			this->_search_stack.pop();

			// check
			int failed_position = this->find_failed_position(sn.s, sn.reversed);
			switch (failed_position) {
				case FOUND:
					if (sn.reversed) reverse(sn.s.begin(), sn.s.end());
					this->_answers.push_back(sn.s);
					break;
				case REVERSE:
					reverse(sn.s.begin(), sn.s.end());
					this->next(sn.s, !sn.reversed);
					break;
				default: {
					char search_char = sn.reversed ? '(' : ')';
					for (int i = 0; i <= failed_position; i++) {
						// not a target char
						if (sn.s[i] != search_char) continue;

						// next
						string removed_string = sn.s.substr(0, i) + sn.s.substr(i + 1);
						this->next(removed_string, sn.reversed);
					}
				}
			}
		}
	}
public:
	vector<string> removeInvalidParentheses(string s) {
		// clean
		this->_answers.clear();
		this->_search_stack = stack<SearchNode>();
		this->_visited = {{ true, {} }, { false, {} }};

		// search
		this->next(s, false);
		this->dfs();

		return this->_answers;
	}
private:
	vector<string> _answers;
	stack<SearchNode> _search_stack;
	unordered_map<bool, unordered_set<string>> _visited;
};

