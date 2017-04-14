class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count[256];
        fill(count, count+256, 0);
        int i = 0, len = 0, distinct = 0;
        for (int j = 0; j < s.size(); j++) {
            if (count[s[j]] == 0) distinct++;
            count[s[j]]++;
            while (distinct > 2) {
                count[s[i]]--;
                if (count[s[i]] == 0) distinct--;
                i++;
            }
            len = max(j - i + 1, len);
        }
        return len;
    }
};

