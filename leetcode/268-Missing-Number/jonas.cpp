class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
            result ^= i + 1;
        }
        return result;
    }
};
