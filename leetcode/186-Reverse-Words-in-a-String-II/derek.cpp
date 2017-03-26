class Solution {
public:
    void reverseWords(string &s) {
        // reverse whole string
        reverse(s.begin(), s.end());

        // revese each word
		int i = 0;
        for (int j = 0; j <= s.size(); j++) {
            if (j == s.size() || s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
    }
};
