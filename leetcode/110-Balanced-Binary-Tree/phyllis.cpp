/**Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int isBalanced(TreeNode* root){
        int lDepth, rDepth;
        lDepth = rDepth = -1;
        return isBalanced(root, &lDepth);
    }
    
    bool isBalanced(TreeNode* root, int *depth) {
        if(!root) return true;

        int lDepth, rDepth;
        lDepth = rDepth = -1;
        bool rBalanced, lBalanced;
        if(root->right != NULL) rBalanced = isBalanced(root->right, &rDepth);
        else rBalanced =true;
        
        if(root->left != NULL) lBalanced = isBalanced(root->left, &lDepth);
        else lBalanced =true;
        
        if(lBalanced && rBalanced){ 
           *depth = (rDepth > lDepth)? rDepth : lDepth;
           *depth = *depth + 1;
           return (abs(rDepth-lDepth) <= 1) ? true : false;
          
        } else return false;
    }
};
