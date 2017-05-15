// Using the long structure is too tricky....

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
    public boolean validateBST(TreeNode root,long min, long max) {
        if(root == null) {
            return true;
        }
        
        if(root.val >= max) {
            return false;
        }
        
        if(root.val <= min) {
            return false;
        }
        
        return validateBST(root.left, min, root.val) && validateBST(root.right, root.val, max);
    }
    
    public boolean isValidBST(TreeNode root) {
        return validateBST(root, Long.MIN_VALUE, Long.MAX_VALUE); 
    }
}
