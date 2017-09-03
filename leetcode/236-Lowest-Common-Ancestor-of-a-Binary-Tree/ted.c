/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;
int traverseLCA(TreeNode*, TreeNode**, TreeNode**, TreeNode**);

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    TreeNode *ans=NULL, *pp=p, *qq=q;
    
    traverseLCA(root, &pp, &qq, &ans);
    
    return ans;
}

int traverseLCA(TreeNode *node, TreeNode **p, TreeNode **q, TreeNode **ans) {
    if (!node || (!*p && !*q)) return 0;
    
    int match = (node == *p || node == *q) ? 1 : 0;
    
    if (node == *p) *p = NULL;
    if (node == *q) *q = NULL;
    
    int left = traverseLCA(node->left, p, q, ans);
    int right = traverseLCA(node->right, p, q, ans);
    
    if (left == 2 || right == 2) return 2;
    
    int count = left + right + match;
    
    if (count == 2) {
        *ans = node;
    }
    
    return count;
}
