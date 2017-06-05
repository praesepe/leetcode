class Solution {
protected:
	int max_value = INT_MIN;

	int find_max(TreeNode* root) {
		if (NULL == root) {
			return 0;
		}

		int left = max(0, find_max(root->left));
		int right = max(0, find_max(root->right));

		max_value = max(max_value, left + right + root->val);
		return max(left, right) + root->val;
	}
public:
    int maxPathSum(TreeNode* root) {
		this->find_max(root);
		return this->max_value;
    }
};
