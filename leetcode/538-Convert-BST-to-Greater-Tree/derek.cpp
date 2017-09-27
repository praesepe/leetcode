class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        //
        // symmetric inorder traversal
        //

        if (root == NULL) {
            return root;
        }

        convertBST(root->right);

        sum += root->val;
        root->val = sum;

        convertBST(root->left);

        return root;
    }
private:
    int sum = 0;
};

