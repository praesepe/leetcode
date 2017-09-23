#include <string.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    bool check(int table[]) {
        return memcmp(table, this->_dummy, sizeof(this->_dummy)) == 0;
    }

public:
    Solution() {
        memset(this->_dummy, 0, sizeof(this->_dummy));
    }

    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};

        int table[26] = {0};
        for (size_t i = 0; i < p.size(); i++) table[p[i] - 'a']++;
        for (size_t i = 0; i < p.size() - 1; i++) table[s[i] - 'a']--;

        vector<int> result;
        size_t offset = p.size() - 1;
        for (size_t i = offset; i < s.size(); i++) {
            table[s[i] - 'a']--;
            if (this->check(table)) result.push_back(i - offset);
            table[s[i - offset] - 'a']++;
        }

        return result;
    }
private:
    int _dummy[26];
};
