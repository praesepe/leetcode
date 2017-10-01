class Solution {
public:
    std::string frequencySort(std::string s) {
        std::unordered_map<char, int> hash;
        std::vector<std::string> sorted(s.size());
        std::string result;

        for (const auto c: s) {
            hash[c]++;
        }
        for (const auto p: hash) {
            sorted[p.second - 1].append(p.second, p.first);
        }
        for (int i = s.size() - 1; i >=0; i--) {
            result.append(sorted[i]);
        }
        return result;
    }
};
