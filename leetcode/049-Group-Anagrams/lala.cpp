#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    string get_key(string s) {
        uint16_t table[26] = {0};
        for (const auto c : s) table[c - 'a']++;

        return string((char*) table, sizeof(table));
        /*
        string key(s.size(), NULL);
        size_t count = 0;
        for (size_t i = 0; i < 26; i++) {
            for (size_t j = 0; j < table[i]; j++) {
                key[count++] = 'a' + i;
            }
        }

        return key;
        */
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umm;
        for (const auto str : strs) {
            string key = this->get_key(str);
            const auto itr = umm.find(key);
            if (itr == umm.end()) {
                umm[key] = vector<string>();
            }
            umm[key].push_back(str);
        }

        vector<vector<string>> result;
        for (auto itr : umm) {
            result.push_back(itr.second);
        }
        return result;

    }
};
