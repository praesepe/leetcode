class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> count(26, 0);
        for (auto ch: t) {
            int idx = ch - 'a';
            count[idx]++;
        }

        int start = 0, end = 0, idx;
        while (end < s.length()) {
            idx = s[end] - 'a';
            if (count[idx] == 0) {
                return false;
            }
            count[idx]--;
            end++;
        }

        return true;
    }
};
