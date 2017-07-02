public class Solution {
    public int searchInsert(int[] nums, int target) {
        int index = nums.length;
        
        for(int i=0; i<nums.length; i++){
            if(target <= nums[i]) {
                index = i;
                break;
            }
        }
        
        return index;
    }
}
