class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> product(n);

        product[0] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            product[i] = product[i - 1] * nums[i];
        }

        product[n-1] = 1;
        for (int i = n - 1; i > 0; i--) {
            int swap = product[i];
            product[i] = swap * product[i-1];
            product[i-1] = swap * nums[i];
        }
        return product;
    }
};
