class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        findMax(root);
        return maxSum;
    }
private:
    int findMax(TreeNode* p) {
        if (p == NULL) return 0;
        int l = findMax(p->left);
        int r = findMax(p->right);
        maxSum = max(l + r + p->val, maxSum);
        int ret = max(l, r) + p->val;
        return ret > 0 ? ret : 0;
    }

    int maxSum;
};
