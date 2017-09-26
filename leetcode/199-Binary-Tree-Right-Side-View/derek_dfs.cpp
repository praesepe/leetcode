class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }

    void dfs(TreeNode* root, int level, vector<int>& result) {
        if (root == NULL) {
            return;
        }

        if (level == result.size()) {
            result.push_back(root->val);
        }

        dfs(root->right, level + 1, result);
        dfs(root->left, level + 1, result);
    }
};
