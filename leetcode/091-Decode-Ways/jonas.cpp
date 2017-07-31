class Solution {
 public:
    int numDecodings(std::string s) {
		std::vector<int> fib(s.size());

		if (s.empty() || s[0] == '0') {
			return 0;
		}

		fib[0] = 1;
		fib[1] = s[1] != '0' ? 1 : 0;
		fib[1] += stoi(s.substr(0, 2)) <= 26 ? 1 : 0;

		for (int i = 2; i < s.size(); i++) {
			fib[i] = s[i] != '0' ? fib[i-1] : 0;
			fib[i] += stoi(s.substr(i - 1, 2)) <= 26 && s[i - 1] != '0'
						  ? fib[i - 2]
						  : 0;
		}
		return fib[s.size()-1];
    }
};
