class Solution {
public:
    string longestPalindrome(string s) {
		size_t max_len  = 0;
		size_t mark     = 0;
		string result   = "";

        for (size_t i = 0; i < s.size(); i++) {
			size_t head = i, tail = i;

			// Same characters must be palindrome
			while (tail+1 < s.size() && s[tail] == s[tail+1]) {
				tail++;
			}

			i = tail;

			do {
				if (s[head] != s[tail]) {
					break;
				}

				if (max_len < tail - head + 1) {
					max_len = tail - head + 1;
					mark = head;
				}

				max_len = max(max_len, tail - head + 1);
			} while (head-- > 0 && tail++ < s.size() - 1);
		}

		if (max_len > 0) {
			result = s.substr(mark, max_len);
		}

		return result;
    }
};
