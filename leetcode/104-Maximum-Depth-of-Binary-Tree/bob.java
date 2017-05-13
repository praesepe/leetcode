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
    public int length(TreeNode root,int maxDepth) {
        if(root == null) {
            return maxDepth;
        }
        
        int leftMaxDepth = root.left == null ?  maxDepth : length(root.left,maxDepth) + 1;
        int rightMaxDepth = root.right == null ?  maxDepth : length(root.right,maxDepth) + 1;
        
        return rightMaxDepth > leftMaxDepth ? rightMaxDepth : leftMaxDepth;
    }
    
    public int maxDepth(TreeNode root) {
        if(root == null) {
            return 0;
        }
        
        return length(root, 1);
    }
}
