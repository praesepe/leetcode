class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var i = 0
        var j = 0
        
        while i < nums.count && j < nums.count {
            // i: the first zero
            // j: the first non-zero next i
            if nums[i] != 0 {
                i += 1
                j = i + 1
                continue
            }
            
            if nums[j] == 0 {
                j += 1
                continue
            }
            
            nums[i] = nums[j]
            nums[j] = 0
            i += 1
            j += 1
        }
        
    }
}
