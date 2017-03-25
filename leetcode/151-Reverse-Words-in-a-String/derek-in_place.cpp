class Solution {
public:
    void reverseWords(string &s) {
        // reverse whole string
        reverse(s.begin(), s.end());

        // length of word
        int len;
        // define reader and writer index
        int r = 0, w = 0;
        while (r < s.size()) {
            if (s[r] != ' ') {
                // if not first word, append a space
                if (w != 0) s[w++] = ' ';
                // copy a token
                len = 0;
                while (r < s.size() && s[r] != ' ') {
                    s[w++] = s[r++];
                    len++;
                }
                // reverse token
                reverse(s.begin() + w - len, s.begin() + w);
            } else {
                r++;
            }
        }
        s.resize(w);
    }
};
