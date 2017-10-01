#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char, unordered_set<string>> dict;

        // for speedup
        for (const auto word : wordDict) {
            char key = word[0];
            auto itr = dict.find(key);
            if (itr == dict.end()) {
                dict[key] = {word};
            } else {
                itr->second.insert(word);
            }
        }


        // init table
        bool success[s.size() + 1];
        memset(success, 0, sizeof(success));
        success[0] = true;

        // F(i) = F(i - 1) && S[i..|Wj|] == Wj
        for (size_t i = 0; i < s.size(); i++) {
            if (!success[i]) continue;

            // find set
            auto itr = dict.find(s[i]);
            if (itr == dict.end()) continue;

            // dp
            auto word_set = itr->second;
            for (auto word : word_set) {
                if (s.substr(i, word.size()) == word) {
                    success[i + word.size()] = true;
                }
            }
        }

        return success[s.size()];
    }
};
