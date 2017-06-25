class Solution {
    func uniquePaths(_ m: Int, _ n: Int) -> Int {
        if m == 0 || n == 0 {
            return 0
        } else if m == 1 || n == 1 {
            return 1
        }
        
        // f(m, n) = f(m - 1, n) + f(m, n - 1)
        var f : [[Int]] = Array(repeating: Array(repeating: 0, count: n + 1), count: m + 1)
        
        for i in 1 ... m {
            f[i][1] = 1
        }
        
        for j in 1 ... n {
            f[1][j] = 1
        }
        
        for i in 2 ... m {
            for j in 2 ... n {
                f[i][j] = f[i - 1][j] + f[i][j - 1]
            }
        }
        
        return f[m][n]
    }
}
