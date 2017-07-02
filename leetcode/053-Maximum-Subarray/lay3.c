int maxSubArray(int* nums, int numsSize) {
    int maxNum = nums[0];
    int numTemp = 0;
    for (int i = 0; i < numsSize; i++) {
        numTemp += nums[i];
        if (numTemp < nums[i]) {
            numTemp = nums[i];
        }
        
        if (numTemp > maxNum) {
            maxNum = numTemp;
        }
    }
    return maxNum;
}
