class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        
        if (nums.size() == 1) {
            return new TreeNode(nums[0]);
        }
        
        // cut in the middle
        int rootIndex = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[rootIndex]);
        
        // recursive
        vector<int> leftNums(nums.begin(), nums.begin() + rootIndex);
        vector<int> rightNums(nums.begin() + rootIndex + 1, nums.end());
        root->left = sortedArrayToBST(leftNums);
        root->right = sortedArrayToBST(rightNums);
        
        return root;
    }
};
