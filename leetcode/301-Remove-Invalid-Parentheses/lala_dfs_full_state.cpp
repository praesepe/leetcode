#include <unordered_set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct SearchNode {
    string s;
    uint32_t pos;
    bool check;

    SearchNode(string s, uint32_t pos, bool check) {
        this->s = s;
        this->pos = pos;
        this->check = check;
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
        uint32_t best_length = 0;
        while (!this->_search_stack.empty()) {
            SearchNode sn = this->_search_stack.top();
            this->_search_stack.pop();

            // check level
            if (best_length > sn.s.size()) continue;

            // found answer
            if (!sn.check && this->is_valid(sn.s)) {
                if (sn.s.size() > best_length) {
                    this->_answers.clear();
                    best_length = sn.s.size();
                }

                this->_answers.insert(sn.s);
            } else {
                // +
                if (sn.pos + 1 <= sn.s.size()) {
                    this->_search_stack.push(SearchNode(sn.s, sn.pos + 1, true));
                }

                // -
                if (sn.pos + 1 <= sn.s.size()) {
                    string eliminate = sn.s.substr(0, sn.pos) + sn.s.substr(sn.pos + 1);
                    this->_search_stack.push(SearchNode(eliminate, sn.pos, false));
                }
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        // clean
        this->_answers.clear();
        this->_search_stack = stack<SearchNode>();

        // search
        this->_search_stack.push(SearchNode(s, 0, false));
        this->dfs();

        return vector<string>(this->_answers.begin(), this->_answers.end());
    }
private:
    unordered_set<string> _answers;
    stack<SearchNode> _search_stack;
};

