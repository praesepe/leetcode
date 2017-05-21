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
        
        if( leftDepth == -1 || rightDepth == -1 ) {
            return -1;
        }
        
        if(Math.abs(leftDepth - rightDepth) > 1) {
            return -1;
        }
        
        return Math.max(leftDepth,rightDepth);
    }
    
    public boolean isBalanced(TreeNode root) {
        if(root == null) {
            return true;
        }
        
        return getDepth(root, 1) != -1;
    }
}
