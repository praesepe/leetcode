/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int findDepth(TreeNode* root, int depth){
        if(root->left == NULL && root->right == NULL)
            return depth;
        
        int rightDepth = (root->right == NULL) ? INT_MAX : findDepth(root->right,depth+1);
        int leftDepth = (root->left == NULL) ? INT_MAX : findDepth(root->left,depth+1);
        return (rightDepth < leftDepth) ? rightDepth : leftDepth;
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        else return findDepth(root, 1);
    }
};
