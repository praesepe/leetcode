class Solution {
    public int[] productExceptSelf(int[] nums) {
        int length = nums.length;
        int[] output = new int[length];
        if(length == 0)
            return output;      
        
        int accumulation = 1;
        for(int i = 0; i < length; i++){
            output[i] = accumulation;
            accumulation *= nums[i];
        }
        
        accumulation = 1;
        for(int i = length - 1; i >= 0; i--){
             output[i] *= accumulation;
             accumulation *= nums[i];    
        }
        
        return output;
    }
}
