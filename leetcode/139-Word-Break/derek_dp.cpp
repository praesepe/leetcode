class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //
        unordered_set<string> dict;
        for (auto word: wordDict) {
            dict.insert(word);
        }

        //
        vector<int> dp(s.length() + 1, false);
        dp[0] = true;

        //
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    string t = s.substr(j, i - j);
                    if (dict.find(t) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.length()];
    }
};

