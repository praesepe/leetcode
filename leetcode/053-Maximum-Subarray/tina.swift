class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {
        // SUM(j...k) = SUM(0...k) - SUM(0...j - 1)
        // ^ keep max   ^ current    ^ keep min
        var max_sub_sum = nums[0]
        var min_sub_sum = 0
        var sum = 0
        
        for num in nums {
            sum += num
            
            if sum - min_sub_sum > max_sub_sum {
                max_sub_sum = sum - min_sub_sum
            }
            
            if sum < min_sub_sum {
                min_sub_sum = sum
            }
        }
        
        return max_sub_sum
    }
}
