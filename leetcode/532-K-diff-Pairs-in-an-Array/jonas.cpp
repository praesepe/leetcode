class Solution {
public:
    int findPairs(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> hash;
        size_t result = 0;

        if (k < 0) {
            return 0;
        }


        for (const auto n: nums) {
            if (hash.find(n) == hash.end()) {
                hash[n] = 1;
            } else {
                hash[n]++;
            }
        }

        for (const auto h: hash) {
            if (k == 0) {
                if (h.second >= 2) {
                    result++;
                }
            } else {
                if (hash.find(h.first + k) != hash.end()) {
                    result++;
                }
            }
        }
        return result;
    }
};
