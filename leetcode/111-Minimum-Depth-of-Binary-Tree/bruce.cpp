class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int dl = minDepth(root->left);
        int dr = minDepth(root->right);
        return 1 + (min(dl, dr) ? min(dl, dr) : max(dl, dr));
    }
};
