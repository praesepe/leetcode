class Solution {
    func climbStairs(_ n: Int) -> Int {
        if n < 2 {
            return 1
        }
        
        var fn = 0, fn_1 = 1, fn_2 = 1
        
        for _ in 2 ... n {
            fn = fn_1 + fn_2
            fn_2 = fn_1
            fn_1 = fn
        }
        
        return fn
    }
}
