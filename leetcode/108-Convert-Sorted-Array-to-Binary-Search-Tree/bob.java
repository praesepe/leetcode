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
    TreeNode getBST(int[] nums, int start, int end) {
        if(start > end) {
            return null;
        }
        
        int index = (start + end) / 2;
        TreeNode bst = new TreeNode(nums[index]);
        bst.left = getBST(nums, start, index - 1);
        bst.right = getBST(nums, index + 1, end);
        
        return bst;
    }
    
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length == 0) {
            return null;
        }
        
        return getBST(nums, 0, nums.length - 1);
    }
}
