class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int preMax = nums[0], curMax;
        int preMin = nums[0], curMin;
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curMax = max(nums[i], max(preMax * nums[i], preMin * nums[i]));
            curMin = min(nums[i], min(preMax * nums[i], preMin * nums[i]));
            result = max(result, curMax);
            preMax = curMax;
            preMin = curMin;
        }

        return result;
    }
};
