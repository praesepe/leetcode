public class Solution {
    public int maxProduct(int[] nums) {
        if(nums.length == 0) {
            return 0;
        }
        
        int product = nums[0];
        int max = nums[0];
        int min = nums[0];
        
        for(int i=1;i < nums.length;i++) {         
            int temp = max; 
            max = Math.max(max*nums[i],Math.max(min*nums[i],nums[i]));
            min = Math.min(temp*nums[i],Math.min(min*nums[i],nums[i]));
            product = Math.max(max,product);
        }
      
      return product;
    }
}
