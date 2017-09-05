class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mp(256, 0);

        int start = 0, end = 0, count = 0;
        while (end < s.length()) {
            mp[s[end++]]++;

            while (mp[s[start]] >= 2 && start < end) {
                start++;
            }
        }

        if (start == s.length()) {
            return -1;
        }

        return start;
    }
};
