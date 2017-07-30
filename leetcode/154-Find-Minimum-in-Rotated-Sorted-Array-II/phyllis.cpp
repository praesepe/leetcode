class Solution {
public:
    int findMin(vector<int>& nums) {      
        int size = nums.size();        
        int prev = nums[0];
        
        if(size == 1) 
            return nums[0];
        
        for(int i = 1 ; i < size; i++){
            if(nums[i-1] > nums[i])
                return nums[i];                   
        }
        
        return nums[0];        
    }
};
