class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0, len;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            len = expandAroundCenter(s, i, i);
            if (len > maxLen) {
                maxLen = len;
                start = i - len / 2;
            }

            len = expandAroundCenter(s, i, i + 1);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }

private:
    int expandAroundCenter(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
};

