#include <cstdio>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;

        TreeNode* l = this->lowestCommonAncestor(root->left, p, q);
        TreeNode* r = this->lowestCommonAncestor(root->right, p, q);

        return l && r ?
            root :
            l ? l : r;
    }
};
