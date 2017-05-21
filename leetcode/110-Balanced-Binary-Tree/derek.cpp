class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;
    }

    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int l = maxDepth(root->left);
        if (l == -1) return -1;
        int r = maxDepth(root->right);
        if (r == -1) return -1;
        return (abs(l - r) <= 1) ? max(l, r) + 1 : -1;
    }
};
