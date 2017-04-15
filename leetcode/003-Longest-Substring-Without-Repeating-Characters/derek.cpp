class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool exists[256] = {false};

        int i = 0, len = 0;
        for (int j = 0; j < s.size(); j++) {
            while (exists[s[j]]) {
                exists[s[i]] = false;
                i++;
            }
            exists[s[j]] = true;
            len = max(j - i + 1, len);
        }

        return len;
    }
};

