class Solution {
protected:
	int result;
	int count;

	void inorder(TreeNode* root) {
		if (NULL == root || count <= 0) {
			return;
		}

		inorder(root->left);
		if (--count == 0) {
			result = root->val;
		}
		inorder(root->right);
	}
public:
    int kthSmallest(TreeNode* root, int k) {
		count = k;
        inorder(root);
		return result;
    }
};
