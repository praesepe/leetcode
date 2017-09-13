class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> mp(256, 0);
        for (auto c: t) {
            mp[c]++;
        }

        int start = 0, end = 0;
        while (end < s.length()) {
            if (mp[s[end++]]-- == 0) {
                return false;
            }
        }

        return true;
    }
};
