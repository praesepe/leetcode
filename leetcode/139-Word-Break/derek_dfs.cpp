class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //
        set<string> dict;
        for (auto word: wordDict) {
            dict.insert(word);
        }

        //
        return dfs(dict, s, 0);
    }

    bool dfs(set<string>& dict, string s, int start) {
        if (start == s.length()) {
            return true;
        }

        for (int i = start + 1; i <= s.length(); i++) {
            string t = s.substr(start, i - start);
            if (dict.find(t) != dict.end()) {
                if (dfs(dict, s, i) == true) {
                    return true;
                };
            }
        }

        return false;
    }
};

