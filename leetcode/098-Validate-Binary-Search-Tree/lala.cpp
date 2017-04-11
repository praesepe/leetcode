#include <stdio.h>
#include <stdint.h>
#include <limits.h>
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
private:
    bool search(TreeNode* node, int64_t min, int64_t max) {
		if (!node) {
			return true;
		}

		if (!(min < node->val && node->val < max)) {
			return false;
		}

		return this->search(node->left, min, node->val) && this->search(node->right, node->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return this->search(root, (int64_t) INT_MIN - 1, (int64_t) INT_MAX + 1);
    }
};
