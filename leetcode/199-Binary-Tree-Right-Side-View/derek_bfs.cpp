
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        queue<TreeNode*> que;
        if (root) {
            que.push(root);
        }

        while (!que.empty()) {
            int n = que.size();

            for (int i = 0; i < n; i++) {
                TreeNode* p = que.front();
                que.pop();

                if (i == n - 1) {
                    result.push_back(p->val);
                }

                if (p->left) {
                    que.push(p->left);
                }
                if (p->right) {
                    que.push(p->right);
                }
            }
        }

        return result;
    }
};

