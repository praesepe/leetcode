class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        var one = 0
        for num in nums {
            one ^= num
        }
        return one
    }
}
