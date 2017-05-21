class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;
    }
private:
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        
        int lmd = maxDepth(root->left);
        int rmd = maxDepth(root->right);
        
        if (lmd == -1 || rmd == -1) {
            return -1;
        }
        
        if (abs(lmd - rmd) > 1) {
            return -1;
        }
        
        return 1 + max(lmd, rmd);
    }
};
