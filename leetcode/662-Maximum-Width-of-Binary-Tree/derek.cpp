class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> left_ends;
        return dfs(root, 1, 0, left_ends);
    }

    int dfs(TreeNode* root, int idx, int depth, vector<int>& left_ends) {
        if (root == NULL) {
            return 0;
        }

        if (depth == left_ends.size()) {
            left_ends.push_back(idx);
        }

        int curr_max = idx - left_ends[depth] + 1;

        int left_max = dfs(root->left, idx * 2, depth + 1, left_ends);
        int right_max = dfs(root->right, idx * 2 + 1, depth + 1, left_ends);

        return max(max(left_max, right_max), curr_max);
    }
};
