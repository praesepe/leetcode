class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
            return t2;
        }
        if (t2 == NULL) {
            return t1;
        }

        //
        // preorder traversal
        //

        // Add numbers
        t1->val +=  t2->val;

        // left subtree
        if (t1->left != NULL && t2->left != NULL) {
            mergeTrees(t1->left, t2->left);

        } else if (t1->left == NULL && t2->left != NULL) {
            t1->left = t2->left;

        } else if (t1->left != NULL && t2->left == NULL) {
            // do nothing

        } else {
            // leaf node, do nothing
        }


        // right subtree
        if (t1->right != NULL && t2->right != NULL) {
            mergeTrees(t1->right, t2->right);

        } else if (t1->right == NULL && t2->right != NULL) {
            t1->right = t2->right;

        } else if (t1->right != NULL && t2->right == NULL) {
            // do nothing

        } else {
            // leaf node, do nothing
        }

        return t1;
    }
};

