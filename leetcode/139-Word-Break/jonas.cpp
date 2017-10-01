class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::vector<bool> arr(s.size() + 1, false);

        arr[0] = true;
        for (size_t i = 0; i < s.size(); i++) {
            if (!arr[i]) {
                continue;
            }

            for (const auto word: wordDict) {
                if (arr[i + word.size()]) {
                    continue;
                }
                if (s.find(word, i) == i) {
                    arr[i + word.size()] = true;
                }
            }
        }
        return arr[s.size()];
    }
};
