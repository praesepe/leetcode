/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        // condition 1:
        //         A
        //        / \
        //       B   D  => 1 + min(2, 1) = 1 + 1 = 2
        //      /
        //     C 
        //
        // condition 2:
        //         A
        //        /
        //       B      => 1 + max(2, 0) = 1 + 2 = 3
        //      /
        //     C
        if (!root) {
            return 0;
        }
        int dl = minDepth(root->left);
        int dr = minDepth(root->right);
        return 1 + (min(dl, dr) ? min(dl, dr) : max(dl, dr));
    }
};
