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
    public int length(TreeNode root,int depth) {
        if(root == null) {
            return depth;
        }
        
        int current = 1;
        if(root.left == null && root.right == null) {
            return current;
        }
        
        if(root.left == null) {
            return current + length(root.right, depth);
        }
        
        if(root.right == null) {
            return current + length(root.left, depth);
        }
        
        int leftMinDepth = length(root.left, depth);
        int rightMinDepth = length(root.right, depth);
        
        return Math.min(leftMinDepth,rightMinDepth) + current;
    }
    
    public int minDepth(TreeNode root) {
        return length(root, 0);
    }
}
