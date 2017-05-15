class Solution {
public:
    int minDepth(TreeNode* root) {
		if (!root) {
			return 0;
		} else if (!root->left || !root->right) {
			return minDepth(root->left) + minDepth(root->right) + 1;
		}
		return min(minDepth(root->left),  minDepth(root->right)) + 1;
    }
};
