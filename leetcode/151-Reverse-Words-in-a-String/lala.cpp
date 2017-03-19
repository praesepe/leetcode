class Solution {
public:
	void reverseWords(string &s) {
		stack<string> result;

		istringstream iss(s);
		string token;
		while (std::getline(iss, token, ' ')) {
			if (token.empty()) {
				continue;
			}

			result.push(token);
		}

		s.clear();
		while (!result.empty()) {
			if (s.empty()) {
				s = result.top();
			} else {
				s.append(" " + result.top());
			}
			result.pop();
		}
	}
};
