class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        vector<int> map(256, 0);
        int start = 0, end = 0, count = 0;

        while (end < s.length()) {
            if (map[s[end++]]++ == 1) {
                count++;
            }

            while (count > 0) {
                if (map[s[start++]]-- == 2) {
                    count--;
                }
            }

            result = max(end - start, result);
        }

        return result;
    }
};
