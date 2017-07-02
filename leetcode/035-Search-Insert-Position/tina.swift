class Solution {
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        var low = 0
        var high = nums.count - 1
        var mid = 0
        
        while low <= high {
            mid = low + (high - low) / 2
            
            if nums[mid] == target {
                return mid
            }
            
            if target > nums[mid] {
                low = mid + 1
            } else {
                high = mid - 1
            }
        }
        
        return low
    }
}
