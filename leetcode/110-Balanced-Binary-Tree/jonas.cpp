class Solution {
protected:
	int getHeight(TreeNode* root) {
		if (!root) {
			return 0;
		}

		int h_left  = getHeight(root->left);
		int h_right = getHeight(root->right);

		if (-1 == h_left || -1 == h_right || 1 < abs(h_left-h_right)) {
			return -1;
		}

		return max(h_left, h_right) + 1;
	}
public:
    bool isBalanced(TreeNode* root) {
        return -1 != getHeight(root);
    }
};
