class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dict : [Int:Int] = [:]
        
        for (index, num) in nums.enumerated() {
            if dict[target - num] != nil {
                return [dict[target - num]!, index]
            }
            
            dict[num] = index
        }
        
        return []
    }
}
