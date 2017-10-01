class Solution {
public:
    bool isPrefix(const string &s, const int pos, const string &word) {
        if (s.length() - pos < word.length()) return false;
        
        for (int i = 0;i < word.length(); i++) {
            if (s[i + pos] != word[i]) {
                return false;
            }
        }
        
        return true;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length(), false);
        int i, j;
        
        dp[0] = true;
        for (i = 0;i < s.length(); i++) {
            if (dp[i]) {
                for (j = 0;j < wordDict.size(); j++) {
                    if (isPrefix(s, i, wordDict[j])) {
                        dp[i + wordDict[j].length()] = true;
                    }
                }
            }
        }
        
        return dp[s.length()];
    }
};
