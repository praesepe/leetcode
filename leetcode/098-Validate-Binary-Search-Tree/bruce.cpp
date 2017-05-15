class Solution {
private:
    bool isValidNode(TreeNode *current, int64_t max, int64_t min) {
        if (!current) {
            return true;
        }
        if (max <= current->val || min >= current->val ) {
            return false;
        }
        return isValidNode(current->left, current->val, min) && isValidNode(current->right, max, current->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        // some test values are beyond integer range
        return isValidNode(root, (int64_t) INT_MAX + 1, (int64_t) INT_MIN - 1);
    }
};
