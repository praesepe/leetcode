class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        
        int dp = p->val - root->val;
        int dq = q->val - root->val;
        
        if (dp > 0 && dq > 0) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (dp < 0 && dq < 0) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        return root;
    }
};
