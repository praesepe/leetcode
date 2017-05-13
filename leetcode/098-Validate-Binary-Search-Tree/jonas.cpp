class Solution {
protected:
	bool isValidBST(TreeNode *root, long maxVal, long minVal) {
		if (!root) {
			return true;
		}

		if (root->val >= maxVal || root->val <= minVal) {
			return false;
		}

		return isValidBST(root->left, root->val, minVal) && isValidBST(root->right, maxVal, root->val);
	}
public:
    bool isValidBST(TreeNode* root) {
		return isValidBST(root, LONG_MAX, LONG_MIN);
    }
};
