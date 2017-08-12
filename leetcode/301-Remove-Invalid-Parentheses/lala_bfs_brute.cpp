#include <unordered_set>
#include <queue>
#include <string>
#include <vector>

using namespace std;

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

    void bfs() {
        bool found = false;
        while (!this->_search_queue.empty()) {
            string s = this->_search_queue.front();
            this->_search_queue.pop();

            // check valid
            if (this->is_valid(s)) {
                this->_answers.push_back(s);
                found = true;
            }

            if (!found) {
                for (size_t i = 0; i < s.size(); i++) {
                    if (s[i] != '(' && s[i] != ')') {
                        continue;
                    }

                    string eliminate = s.substr(0, i) + s.substr(i + 1);
                    if (this->_visited.find(eliminate) != this->_visited.end()) {
                        continue;
                    }
                    this->_search_queue.push(eliminate);
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
        this->_search_queue = queue<string>();

        // search
        this->_search_queue.push(s);
        this->_visited.insert(s);
        this->bfs();

        return this->_answers;
    }
private:
    vector<string> _answers;
    unordered_set<string> _visited;
    queue<string> _search_queue;
};
