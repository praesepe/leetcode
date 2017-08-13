class Solution {
 public:
    int numDecodings(std::string s) {
		std::vector<int> fib(s.size()+1);

		if (s.empty() || s[0] == '0') {
			return 0;
		}

		fib[0] = 1;
		fib[1] = 1;

		for (int i = 2; i <= s.size(); i++) {
			// walk one step, prevent 0
			fib[i] = s[i-1] != '0' ? fib[i-1] : 0;

			// walk two steps, prevent cases like 02(<10) or 34(>26)
			int n = stoi(s.substr(i - 2, 2));
			fib[i] += n >= 10 && n <= 26 ? fib[i - 2] : 0;
		}
		return fib[s.size()];
    }
};
