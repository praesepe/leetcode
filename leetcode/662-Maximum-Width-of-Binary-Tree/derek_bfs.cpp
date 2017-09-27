class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int result = 0;

        queue<pair<TreeNode*, int>> que;
        que.push(make_pair(root, 1));

        while (!que.empty()) {

            int n = que.size();
            int left_idx = que.front().second;
            for (int i = 0; i < n; i++) {
                TreeNode* p = que.front().first;
                int curr_idx = que.front().second;
                que.pop();

                result = max(curr_idx - left_idx + 1, result);

                if (p->left) {
                    que.push(make_pair(p->left, curr_idx * 2));
                }
                if (p->right) {
                    que.push(make_pair(p->right, curr_idx * 2 + 1));
                }
            }
        }

        return result;
    }
};

