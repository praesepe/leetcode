class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //
        unordered_set<string> dict;
        for (auto word: wordDict) {
            dict.insert(word);
        }

        //
        unordered_set<int> visited;

        //
        queue<int> que;
        que.push(0);

        while (!que.empty()) {
            int start = que.front();
            que.pop();

            if (visited.find(start) != visited.end()) {
                continue;
            }
            visited.insert(start);

            for (int i = start + 1; i <= s.length(); i++) {
                string t = s.substr(start, i - start);
                if (dict.find(t) != dict.end()) {
                    que.push(i);
                    if (i == s.length()) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

