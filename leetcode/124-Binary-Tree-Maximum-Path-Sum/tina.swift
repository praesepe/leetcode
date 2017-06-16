class Solution {
    func maxPathSum(_ root: TreeNode?, max: inout Int) -> Int {
        if root == nil {
            return 0
        }
        
        let node: TreeNode! = root
        let l = maxPathSum(node.left, max: &max)
        let r = maxPathSum(node.right, max: &max)
        
        let sum = Swift.max(node.val, l + node.val, r + node.val)
        max = Swift.max(max, sum, l + node.val + r)
        
        return sum
    }
    
    func maxPathSum(_ root: TreeNode?) -> Int {
        var max = Int(Int32.min)
        maxPathSum(root, max: &max)
        
        return max
    }
}
