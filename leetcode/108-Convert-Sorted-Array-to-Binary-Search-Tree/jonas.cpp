class Solution {
protected:
	TreeNode* getBST(vector<int>& nums, int low, int high) {
		if (0 > high - low) {
			return NULL;
		}

		int index      = low + (high - low) / 2;
		TreeNode* root = new TreeNode(nums[index]);
		root->right    = getBST(nums, index+1, high);
		root->left     = getBST(nums, low, index-1);

		return root;
	}
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		return getBST(nums, 0, nums.size() - 1);
    }
};
