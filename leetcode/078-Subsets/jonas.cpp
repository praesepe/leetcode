class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result {{}};

        for (const auto n: nums) {
            size_t m = result.size();
            for (size_t i = 0; i < m; i++) {
                std::vector<int> tmp(result[i]);
                tmp.push_back(n);
                result.push_back(tmp);
            }
        }
        return result;
    }
};
