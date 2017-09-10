class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        // product from left
        int pre_product = 1;
        for (int i = 0; i < nums.length; i++) {
            res[i] = pre_product;
            pre_product *= nums[i];
        }
        // product from right
        pre_product = 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            res[i] *= pre_product;
            pre_product *= nums[i];
        }


        return res;
    }
}