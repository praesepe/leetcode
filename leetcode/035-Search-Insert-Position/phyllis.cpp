class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int start = 0;
        int end = size - 1;
        int idx = (size - 1 - 0) / 2;
        
        if(size == 0) 
            return 0;
        if(target <= nums[0])
            return 0;
        if(target > nums[size-1])
            return size;
        
        while(end - start > 1){      
            
            if(nums[idx] == target){
                return idx;
         
            } else if(nums[idx] > target){   
                start = 0;
                end = idx;
                idx = start + (end - start) / 2;
            
            } else {
                start = idx;            
                idx = start + (end - start) / 2;            
            }
        }
        
        return (start + 1);        
    }
};
