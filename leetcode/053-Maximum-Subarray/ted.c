int maxSubArray(int* nums, int numsSize) {
    int max_sum = nums[0];
    int sum     = nums[0];
    
    for (int i=1; i<numsSize; i++) {
        sum = (sum < 0) ? nums[i] : nums[i] + sum;
        max_sum = (sum > max_sum) ? sum : max_sum;
    }
    
    return max_sum;
}
