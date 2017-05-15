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
    public int length(TreeNode root) {
        if(root == null) {
            return 0;
        }
        
        int current = 1;
        if(root.left == null && root.right == null) {
            return current;
        }
        
        //only one path
        if(root.left == null) {
            return current + length(root.right);
        }
        
        if(root.right == null) {
            return current + length(root.left);
        }
        
        int leftMinDepth = length(root.left);
        int rightMinDepth = length(root.right);
        
        return Math.min(leftMinDepth,rightMinDepth) + current;
    }
    
    public int minDepth(TreeNode root) {
        return length(root);
    }
}
