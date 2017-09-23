#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int table[26] = {0};

        for (const auto c : t) table[c - 'a']++;
        for (const auto c : s) table[c - 'a']--;

        for (size_t i = 0; i < 26; i++) {
            if (table[i] != 0) return false;
        }

        return true;
    }
};
