class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result;
        std::array<int, 26> table({0});
        size_t start = 0;
        size_t end = 0;
        size_t count = p.length();

        for (const auto c: p) {
            table[c - 'a']++;
        }

        while (end < s.length()) {
            table[s[end] - 'a']--;
            if (table[s[end] - 'a'] >= 0) {
                count--;
            }

            if (count == 0) {
                result.push_back(start);
            }

            if (end - start + 1 == p.length()) {
                table[s[start] - 'a']++;
                if (table[s[start] - 'a'] > 0) {
                    count++;
                }
                start++;
            }
            end++;
        }

        return result;
    }
};
