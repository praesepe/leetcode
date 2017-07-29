class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                // pop a node from queue
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                // push left child
                if (node->left) {
                    q.push(node->left);
                }
                // push right child
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(level);
        }

        return res;
    }
};
