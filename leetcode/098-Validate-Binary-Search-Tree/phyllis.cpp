/**
 *Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root, long small, long big) {
        if (root == NULL) {  
            return true;  
        }
        
        if (root->val <= small) return false;  
        if (root->val >= big) return false;  
            
        //return leftSubTree && rightSubTree;*/
        return isValidBST(root->left, small, root->val) && isValidBST(root->right, root->val, big);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }
};
