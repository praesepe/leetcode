#include <unordered_set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct SearchNode {
    string s;
    uint32_t level;

    SearchNode(string s, uint32_t level) {
        this->s = s;
        this->level = level;
    }
};

class Solution {
private:
    bool is_valid(string s) {
        int count = 0;

        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                count--;
            }

            if (count < 0) return false;
        }

        return count == 0;
    }

    void dfs() {
        uint32_t best_level = UINT_MAX;
        while (!this->_search_stack.empty()) {
            SearchNode sn = this->_search_stack.top();
            this->_search_stack.pop();
            // check level
            if (best_level < sn.level) continue;

            // found answer
            if (this->is_valid(sn.s)) {
                if (sn.level < best_level) {
                    this->_answers.clear();
                    best_level = sn.level;
                }
                this->_answers.push_back(sn.s);
            } else {
                for (size_t i = 0; i < sn.s.size(); i++) {
                    if (sn.s[i] != '(' && sn.s[i] != ')') {
                        continue;
                    }

                    string eliminate = sn.s.substr(0, i) + sn.s.substr(i + 1);
                    if (this->_visited.find(eliminate) != this->_visited.end()) {
                        continue;
                    }
                    this->_search_stack.push(SearchNode(eliminate, sn.level + 1));
                    this->_visited.insert(eliminate);
                }
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        // clean
        this->_answers.clear();
        this->_visited.clear();
        this->_search_stack = stack<SearchNode>();

        // search
        this->_search_stack.push(SearchNode(s, 0));
        this->_visited.insert(s);
        this->dfs();

        return this->_answers;
    }
private:
    vector<string> _answers;
    unordered_set<string> _visited;
    stack<SearchNode> _search_stack;
};

