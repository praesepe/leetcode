class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        var i = 0
        var j = numbers.count - 1
        var sum = 0
        
        while i < j {
            sum = numbers[i] + numbers[j]
            if sum == target {
                return [ i+1, j+1 ]
            }
            
            if sum < target {
                i += 1
            } else if sum > target {
                j -= 1
            }
        }
        
        return []
    }
}
