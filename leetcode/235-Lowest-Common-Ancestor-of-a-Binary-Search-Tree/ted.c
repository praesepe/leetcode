/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root) return NULL;
    
    if (root->val == p->val || root->val == q->val) return root;
    
    int compare = 0;
    compare += (root->val > p->val) ? 1 : -1;
    compare += (root->val > q->val) ? 1 : -1;
    
    switch (compare) {
        case 0:
            return root;
        case 2:
            return lowestCommonAncestor(root->left, p, q);
        default:
            return lowestCommonAncestor(root->right, p, q);
    }
}
