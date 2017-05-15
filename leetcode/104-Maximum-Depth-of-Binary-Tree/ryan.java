public class Solution {

    public int maxDepth_root2leaf(TreeNode root, int depth) {
        if (root == null) {
            return depth;
        }
        depth++;

        return Math.max(maxDepth_root2leaf(root.left, depth), maxDepth_root2leaf(root.right, depth));
    }

    public int maxDepth_root2leaf(TreeNode root) {
        return maxDepth_root2leaf(root, 0);
    }

    public int maxDepth_leaf2root(TreeNode root) {
        return root == null ? 0 : Math.max(maxDepth_leaf2root(root.left), maxDepth_leaf2root(root.right)) + 1;
    }

    public int maxDepth_stack(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Stack<TreeNodeDepth> stack = new Stack();
        stack.push(new TreeNodeDepth(root, 1));
        int maxDepth = 0;
        while (!stack.empty()) {
            TreeNodeDepth tnd = stack.pop();
            maxDepth = Math.max(maxDepth, tnd.depth);
            if (tnd.tn.left != null) {
                stack.push(new TreeNodeDepth(tnd.tn.left, tnd.depth + 1));
            }
            if (tnd.tn.right != null) {
                stack.push(new TreeNodeDepth(tnd.tn.right, tnd.depth + 1));
            }
        }
        return maxDepth;
    }

    public int maxDepth_queue(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        Queue<TreeNode> q = new LinkedList(); 
        q.offer(root);
        int maxDepth = 0;
        int orgSize;
        TreeNode tn;
        while(!q.isEmpty()) {
            maxDepth++;
            orgSize = q.size();
            for(int i = 0; i < orgSize; i++) {
                tn = q.poll();
                if(tn.left != null) {
                    q.offer(tn.left);
                }
                if(tn.right != null) {
                    q.offer(tn.right);
                }
            }
        }
        return maxDepth;
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