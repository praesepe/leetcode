int findMin(int* nums, int numsSize) {
    int start=0;
    int end=numsSize-1;
    
    while (end > start) {
        if (nums[start] < nums[end]) {
            return nums[start];
        }
        
        int median = (start + end) / 2;
        
        if (nums[start] < nums[median]) {
            start = median + 1;
        } else {
            end = median;
            start = start+1;
        }
    }
    
    return nums[start];
}
