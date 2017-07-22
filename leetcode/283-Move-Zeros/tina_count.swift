class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var zeroIdx = 0
        
        for num in nums {
            if num == 0 {
                continue
            }
            
            nums[zeroIdx] = num
            zeroIdx += 1
        }
        
        for i in stride(from: zeroIdx, to: nums.count, by: 1) {
            nums[i] = 0
        }
        
    }
}
