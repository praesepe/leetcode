#include <climits>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidSubBST(struct TreeNode* root, int max, int min);

bool isValidBST(struct TreeNode* root) {
    return !root || isValidSubBST(root, INT_MAX, INT_MIN);
}

bool isValidSubBST(struct TreeNode* root, int max, int min) {
    if (root->val == INT_MAX && root->right) {
        return false;
    }
    
    if (root->val == INT_MIN && root->left) {
        return false;
    }
    
    if (root->val > max || root->val < min) {
        return false;
    }
    
    return (!root->left || isValidSubBST(root->left, root->val-1, min)) && (!root->right || isValidSubBST(root->right, max, root->val+1));
}
