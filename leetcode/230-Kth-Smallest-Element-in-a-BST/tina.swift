class Solution {
    func count(_ root: TreeNode?) -> Int {
        if (root != nil) {
            return 1 + count(root!.left) + count(root!.right)
        }
        return 0
    }
    
    func kthSmallest(_ root: TreeNode?, _ k: Int) -> Int {
        // NO need to check root is nil or NOT with valid assumption
        let pos = count(root!.left) + 1
        if (k == pos) {
            return root!.val
        } else if (k < pos) {
            return kthSmallest(root!.left, k)
        }
        return kthSmallest(root!.right, k - pos)
    }
}
