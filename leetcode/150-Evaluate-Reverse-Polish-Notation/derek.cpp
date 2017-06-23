class Solution {
public:
    stack<int> _stack;

    int evalRPN(vector<string>& tokens) {

        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];

            if (s == "+" || s == "-" || s == "*" || s == "/") {

                int y = _stack.top();
                _stack.pop();
                int x = _stack.top();
                _stack.pop();

                if (s == "+") {
                    _stack.push(x + y);
                } else if (s == "-") {
                    _stack.push(x - y);
                } else if (s == "*") {
                    _stack.push(x * y);
                } else {
                    _stack.push(x / y);
                }
            } else {
                _stack.push(stoi(s));
            }
        }

        return _stack.top();
    }
};
