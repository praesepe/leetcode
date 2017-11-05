class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        std::stack<TreeNode*> stack;
        int sum = 0;
        bool done = false;
        TreeNode* cursor = root;

        while (!done) {
            if (cursor) {
                stack.push(cursor);
                cursor = cursor->right;
            } else {
                if (stack.empty()) {
                    done = true;
                } else {
                    cursor = stack.top();
                    stack.pop();
                    cursor->val += sum;
                    sum = cursor->val;
                    cursor = cursor->left;
                }
            }
        }
        return root;
    }
};
