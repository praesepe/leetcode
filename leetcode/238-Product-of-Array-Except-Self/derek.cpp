class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fromBegin(n, 1);
        vector<int> fromEnd(n, 1);
        vector<int> result(n, 1);

        for (int i = 1; i < n; i++) {
            fromBegin[i] = fromBegin[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            fromEnd[i] = fromEnd[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            result[i] = fromBegin[i] * fromEnd[i];
        }

        return result;
    }
};
