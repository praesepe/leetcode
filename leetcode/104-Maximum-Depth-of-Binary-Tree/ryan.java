public class Solution {
    public int maxDepth_root2leaf(TreeNode root, int depth) {
        if (root == null) {
            return depth;
        }
        depth++;
        return Math.max(maxDepth_root2leaf(root.left, depth), maxDepth_root2leaf(root.right, depth));
    }

    public int maxDepth_root2leaf(TreeNode root) {
        return maxDepth_root2leaf(root, 0);
    }

    public int maxDepth_leaf2root(TreeNode root) {
        return root == null ? 0 : Math.max(maxDepth_leaf2root(root.left), maxDepth_leaf2root(root.right)) + 1;
    }
}