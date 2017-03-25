class Solution {
protected:
	bool isAlphanumeric(char c) {
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
	}

public:
	bool isPalindrome(string s) {
		if (s.empty()) {
			return true;
		}

		for (size_t i = 0, j = s.size() -1; i < j; i++, j--) {
			// Skip non-alphabetic characters
			while (i < s.size() && !isAlphanumeric(s[i])) {
				i++;
			}

			while (j > 0 && !isAlphanumeric(s[j])) {
				j--;
			}

			if (i >= j) {
				return true;
			}

			if (0 != strncasecmp(&s[i], &s[j], 1)) {
				return false;
			}

		}
		return true;
	}
};
