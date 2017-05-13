int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
}
