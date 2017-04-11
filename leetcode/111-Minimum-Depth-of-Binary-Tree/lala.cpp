#include <stdio.h>
#include <algorithm>

using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        } else if (!root->left && !root->right) {
            return 1;
        } else if (!root->left) {
            return 1 + this->minDepth(root->right);
        } else if (!root->right) {
            return 1 + this->minDepth(root->left);
        }

        return 1 + min(this->minDepth(root->left), this->minDepth(root->right));
    }
};
