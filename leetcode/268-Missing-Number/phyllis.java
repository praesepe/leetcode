class Solution {
    public int missingNumber(int[] nums) {
        int length = nums.length;
        int sum = (length + 1) * (0 + length) / 2;
        
        for(int i = 0; i < length ; i++){
            sum -= nums[i];
        }
        
        return sum;
    }
}
