public class Solution {
    public int maxSubArray(int[] nums) {
        int max,sum;
        max = sum = nums[0];
        
        for(int i=1; i<nums.length; i++) {
            sum = sum < 0 ? nums[i] : sum + nums[i];
            max = Math.max(max,sum);
        }
        
        return max;
    }
}
