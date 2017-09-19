class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;

        for (auto s: strs) {
            string t = s;
            sort(t.begin(), t.end());
            if (mp.find(t) == mp.end()) {
                mp[t] = multiset<string>();
            }
            mp[t].insert(s);
        }

        vector<vector<string>> result;
        for (auto it: mp) {
            vector<string> anagrams(it.second.begin(), it.second.end());
            result.push_back(anagrams);
        }

        return result;
    }
};

