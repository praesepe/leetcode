/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {   
    ArrayList<String> list;
    
    public List<String> binaryTreePaths(TreeNode root) {
        list = new ArrayList<String>();
        traversal(root, "");
    }

    public String traversal(TreeNode root, String str){
        str + "->" + root.data;        
        if(root.left == NULL && root.right == NULL)
            return str;
        if(root.left != NULL) 
            return traversal(root.left, str);
        if(root.right != NULL) 
            return traversal(root.right, str);
        list.add(str);        
    }
}

