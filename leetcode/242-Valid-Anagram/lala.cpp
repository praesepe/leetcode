#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int dummy[26] = {0};
        int table[26] = {0};

        for (const auto c : t) table[c - 'a']++;
        for (const auto c : s) table[c - 'a']--;

        return memcmp(dummy, table, sizeof(dummy)) == 0;
    }
};
