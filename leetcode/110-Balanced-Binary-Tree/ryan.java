public class Solution {
    public int depth(TreeNode tn) {
        if(tn == null) {
            return 0;
        }
        
        int leftDepth = depth(tn.left);
        if(leftDepth == -1) {
            return -1;
        }
        int rightDepth = depth(tn.right);
        if(rightDepth == -1) {
            return -1;
        }
        if(Math.abs(leftDepth - rightDepth) > 1) {
            return -1;
        }
        
        return Math.max(leftDepth, rightDepth) + 1;
    }

    public boolean isBalanced(TreeNode root) {
        return depth(root) != -1;
    }
}