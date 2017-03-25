class Solution {
private:
	void reverseString(string &s, size_t start, size_t end) {
		char c;
		for(size_t i = start, j = end; i < j; i++, j--) {
			//swap
			c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}
public:
	void reverseWords(string &s) {
		if (s.empty()) {
			return;
		}

		reverseString(s, 0, s.size() - 1);

		size_t start=0, end, next_space;

		while (start < s.size()) {
			next_space = s.find(" ", s.find_first_not_of(" ", start));
			end = next_space == string::npos ? s.size() - 1 : next_space - 1;

			reverseString(s, start, end);

			start = s.find(" ", start) == string::npos ? string::npos : s.find(" ", start)+1;
		}

		// right trim
		end = s.find_last_not_of(" ");
		s = end == string::npos ? "" : s.substr(0, end+1);
	}
};
