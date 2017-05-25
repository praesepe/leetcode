class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = 0;
        for (int i = 0; i < nums.size(); i++) {
            value ^= nums[i];
        }
        return value;
    }
};
