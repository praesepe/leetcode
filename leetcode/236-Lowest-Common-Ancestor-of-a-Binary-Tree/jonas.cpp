class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::unordered_map<TreeNode*, int> map;
        std::stack<TreeNode*> stack;

        // post order traverse
        do {
            while (root && map.find(root) == map.end()) {
                if (root->right) {
                    stack.push(root->right);
                }
                stack.push(root);
                root = root->left;
            }

            root = stack.top();
            stack.pop();

            if (!stack.empty() && stack.top() == root->right) {
                stack.pop();
                stack.push(root);
                root = root->right;
            } else {
                map[root] = 0;
                map[root] += root == p || root == q ? 1 : 0;
                map[root] += root->left ? map[root->left] : 0;
                map[root] += root->right ? map[root->right] : 0;
                if (map[root] == 2) {
                    break;
                }
            }
        } while (!stack.empty());
        return root;
    }
};
