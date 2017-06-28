class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        vector<int> dp(nums.size());
        int p = nums[0], q;
        int res = p;

        for (int i = 1; i < nums.size(); i++) {
            q = max((p + nums[i]), nums[i]);
            res = max(res, q);
            p = q;
        }

        return res;
    }
};
