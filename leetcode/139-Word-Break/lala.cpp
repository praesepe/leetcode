#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_multimap<char, string> dict;

        // for speedup
        for (const auto word : wordDict) {
            dict.insert(make_pair(word[0], word));
        }

        bool success[s.size() + 1];
        memset(success, 0, sizeof(success));

        success[0] = true;
        for (size_t i = 0; i < s.size(); i++) {
            if (!success[i]) continue;

            auto range = dict.equal_range(s[i]);
            for (auto itr = range.first; itr != range.second; ++itr) {
                string word = itr->second;
                if (s.substr(i, word.size()) == word) {
                    success[i + word.size()] = true;
                }
            }
        }

        return success[s.size()];
    }
};
