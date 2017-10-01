class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> result({0});

        for (int i = 1; i <= n; i++) {
            for (int j = std::pow(2, i - 1) - 1; j >= 0; j--) {
                result.push_back(result[j] | 1 << (i - 1));
            }
        }
        return result;
    }
};
