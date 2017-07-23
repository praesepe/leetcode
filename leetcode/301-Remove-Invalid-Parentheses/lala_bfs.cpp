#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>

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

	void bfs(queue<SearchNode> &q) {
		while (!q.empty()) {
			SearchNode& sn = q.front();
			if (this->_visited[sn.reversed].find(sn.s) != this->_visited[sn.reversed].end()) {
				q.pop();
				continue;
			}
			this->_visited[sn.reversed].insert(sn.s);

			// check
			int failed_position = this->find_failed_position(sn.s, sn.reversed);
			switch (failed_position) {
				case FOUND:
					if (sn.reversed) reverse(sn.s.begin(), sn.s.end());
					this->_answers.push_back(sn.s);
					break;
				case REVERSE:
					reverse(sn.s.begin(), sn.s.end());
					q.push(SearchNode(sn.s, !sn.reversed));
					break;
				default: {
							 char search_char = sn.reversed ? '(' : ')';
							 for (int i = 0; i <= failed_position; i++) {
								 if (sn.s[i] != search_char) continue;
								 string removed_string = sn.s.substr(0, i) + sn.s.substr(i + 1);
								 q.push(SearchNode(removed_string, sn.reversed));
							 }
						 }
			}

			q.pop();
		}

	}
public:
	vector<string> removeInvalidParentheses(string s) {
		//
		this->_answers.clear();
		this->_visited = {{ true, {} }, { false, {} }};

		//
		queue<SearchNode> q;

		int failed_position = this->find_failed_position(s, false);
		switch (failed_position) {
			case FOUND:
				return { s };
			case REVERSE:
				reverse(s.begin(), s.end());
			default:
				q.push(SearchNode(s, failed_position == REVERSE));
				this->bfs(q);
		}

		return this->_answers;
	}
private:
	vector<string> _answers;
	unordered_map<bool, unordered_set<string>> _visited;
};
