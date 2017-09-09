#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.a
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;

        int min_value = min(p->val, q->val);
        int max_value = max(p->val, q->val);

        if (min_value <= root->val && root->val <= max_value) {
            return root;
        } else {
            return max_value > root->val ?
                lowestCommonAncestor(root->right, p, q) :
                lowestCommonAncestor(root->left, p, q);
        }
    }
};
