class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(
            std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> result;
        std::unordered_map<std::string, int> hash;

        for (const auto s: strs) {
            std::string word = s;
            std::sort(word.begin(), word.end());

            if (hash.find(word) == hash.end()) {
                hash[word] = result.size();
                result.push_back({s});
            } else {
                result[hash[word]].push_back(s);
            }
        }
        return result;
    }
};
