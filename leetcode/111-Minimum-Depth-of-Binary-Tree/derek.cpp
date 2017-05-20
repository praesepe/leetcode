class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* rightMost = root;
        int depth = 1;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left == NULL && node->right == NULL) break;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            if (node == rightMost) {
                depth++;
                rightMost = (node->right != NULL) ? node->right : node->left;
            }
        }

        return depth;
    }
};
