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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new LinkedList<>();
        if (root == null) {
            return ans;
        }
        Stack<TreeNodeDepth> stack = new Stack();
        stack.add(new TreeNodeDepth(root, 0));
        while (!stack.empty()) {
            TreeNodeDepth current = stack.pop();
            if(ans.size() == current.depth) {
                ans.add(new LinkedList<Integer>());
            }
            ans.get(current.depth).add(current.tn.val);
            // add node
            if(current.tn.right != null) {
                stack.add(new TreeNodeDepth(current.tn.right, current.depth + 1));
            }
            if(current.tn.left != null) {
                stack.add(new TreeNodeDepth(current.tn.left, current.depth + 1));
            }
        }

        return ans;
    }
    
    public class TreeNodeDepth {

        TreeNode tn;
        int depth;

        TreeNodeDepth(TreeNode tn, int depth) {
            this.tn = tn;
            this.depth = depth;
        }
    }
}