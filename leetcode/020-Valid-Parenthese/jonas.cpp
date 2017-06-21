class Solution {
protected:
	stack<char> sta;

	const char pop() {
		if (this->sta.empty()) {
			return ' ';
		}
		char c = sta.top();
		sta.pop();
		return c;
	}
public:
    bool isValid(string s) {
        for(char& c: s) {
			switch(c) {
				case '{':
				case '[':
				case '(':
					this->sta.push(c);
					break;
				case '}':
					if (this->pop() != '{') {
						return false;
					}
					break;
				case ']':
					if (this->pop() != '[') {
						return false;
					}
					break;
				case ')':
					if (this->pop() != '(') {
						return false;
					}
					break;
			}
		}
		return this->sta.empty();
    }
};
