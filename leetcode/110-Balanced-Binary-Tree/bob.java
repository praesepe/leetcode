/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int getDepth(TreeNode root,int depth) {
        if(root == null) {
            return depth - 1;
        }
        
        if(root.left == null && root.right == null) {
            return depth;
        }
        
        int leftDepth = getDepth(root.left, depth + 1);
        int rightDepth = getDepth(root.right, depth + 1);
        
        return Math.max(leftDepth, rightDepth);
    }
    
    public boolean isBalanced(TreeNode root) {
        if(root == null) {
            return true;
        }
        
        if(root.left == null && root.right == null) {
            return true;
        }
        
        int leftDepth =  getDepth(root.left, 1);
        int rightDepth = getDepth(root.right, 1);
        
        return Math.abs(leftDepth - rightDepth) <= 1  && isBalanced(root.left) && isBalanced(root.right);
    }
}
