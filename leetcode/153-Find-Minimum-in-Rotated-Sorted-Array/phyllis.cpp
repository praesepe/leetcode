class Solution {
public:
 
    int findMin(vector<int>& nums) {     
        int size = nums.size();        
        
        if(size == 1) 
            return nums[0];
        
        int prev = nums[0];
        for(int i = 1 ; i < size; i++){
            if(nums[i] < prev)
                return nums[i];
                
            prev = nums[i];
        }
        
        return nums[0];
    }
};
