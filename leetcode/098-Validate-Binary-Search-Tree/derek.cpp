class Solution {
private:
    TreeNode* prev;
public:
    bool isValidBST(TreeNode* root) {
        prev = NULL;
        return valid(root);
    }

    bool valid(TreeNode* root) {
        if (root == NULL) return true;

        if (!valid(root->left)) return false;

        if (prev && prev->val >= root->val) return false;
        prev = root;

        if (!valid(root->right)) return false;

        return true;
    }
};
