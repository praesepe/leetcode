class Solution {
private:
    bool check(char c) {
        if (this->_stack.empty()) {
            return false;
        }

		if (this->_stack.top() != this->_lookup[c]) {
			return false;
		}

		this->_stack.pop();
		return true;
    }
public:
    Solution() {
        this->_lookup[')'] = '(';
		this->_lookup['}'] = '{';
		this->_lookup[']'] = '[';
    }

	bool isValid(string s) {
		bool result = true;

        for (int i = 0; i < s.size() && result; i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    this->_stack.push(s[i]);
                    break;
                case ')':
                case ']':
                case '}':
                    result = this->check(s[i]);
                    break;
            }
        }

        return result && this->_stack.empty();
    }

private:
    unordered_map<char, char> _lookup;
    stack<char> _stack;
};
