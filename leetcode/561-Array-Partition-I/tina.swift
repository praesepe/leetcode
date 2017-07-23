class Solution {
    func arrayPairSum(_ nums: [Int]) -> Int {
        var sortedNums = nums.sorted()
        var sum = 0

        for i in stride(from: 0, to: nums.count, by: 2){
            sum += sortedNums[i]
        }
        
        return sum
    }
}
