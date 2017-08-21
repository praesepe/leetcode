class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;

        if (root) {
            dfs(root, path, result);
        }

        return result;
    }

    void dfs(TreeNode* root, vector<int>& path, vector<string>& result) {
        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            string s;
            for (int i = 0; i < path.size(); i++) {
                s += (i == 0) ? to_string(path[i]) : "->" + to_string(path[i]);
            }
            result.push_back(s);
        }

        if (root->left) {
            dfs(root->left, path, result);
        }
        if (root->right) {
            dfs(root->right, path, result);
        }

        path.pop_back();
    }
};
