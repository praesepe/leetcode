class Solution {
protected:
	stack<int> s;
	int operate(string op, int n1, int n2) {
		if (op == "+") {
			return n1 + n2;
		} else if (op == "-") {
			return n1 - n2;
		} else if (op == "*") {
			return n1 * n2;
		} else if (op == "/") {
			return n1 / n2;
		} else {
			throw std::invalid_argument("Detect invalid operator");
		}
	}

	int pop() {
		int result = this->s.top();
		this->s.pop();
		return result;
	}
public:
    int evalRPN(vector<string>& tokens) {
        for (size_t i = 0; i < tokens.size(); i++) {
			try {
				s.push(stoi(tokens[i]));
			} catch (const std::invalid_argument& e) {
				cout<< s.size() << endl;
				s.push(operate(tokens[i], this->pop(), this->pop()));
			}
		}
		return s.top();
    }
};
