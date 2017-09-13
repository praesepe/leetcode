ass Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> mp(256, 0);
        int start = 0, end = 0, count = p.length();

        // prepare
        for (char c: p) {
            mp[c]++;
        }

        // loop
        while (end < s.length()) {
            if (mp[s[end++]]-- > 0) {
                count--;
            }

            if (end - start > p.length()) {
                if (mp[s[start++]]++ >= 0) {
                    count++;
                }
            }

            if (count == 0) {
                result.push_back(start);
            }
        }

        return result;
    }
};
