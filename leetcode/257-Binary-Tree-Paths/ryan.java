class Solution {

    List<String> answer = new ArrayList();

    public List<String> binaryTreePaths(TreeNode root) {
        if (root != null) {
            binaryTreePaths(root, "");
        }
        return answer;
    }

    private void binaryTreePaths(TreeNode root, String path) {
        if (root.left == null && root.right == null) {
            answer.add(path + root.val);
        }
        if (root.left != null) {
            binaryTreePaths(root.left, path + root.val + "->");
        }
        if (root.right != null) {
            binaryTreePaths(root.right, path + root.val + "->");
        }
    }
}