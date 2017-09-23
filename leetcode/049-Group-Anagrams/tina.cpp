class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> hash;
        
        for (int i = 0;i < strs.size(); i++) {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            
            if (hash.find(sortedStr) == hash.end()) {
                hash[sortedStr] = result.size();
                vector<string> row;
                result.push_back(row);
            }
            result[hash[sortedStr]].push_back(strs[i]);
        }
        
        return result;
    }
};
