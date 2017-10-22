#include <vector>

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
private:
    void traverse(TreeNode* root, size_t depth, vector<int> &result) {
        if (!root) return;
        // insert to result
        if (depth == result.size()) {
            result.push_back(root->val);
        } else {
            result[depth] = root->val;
        }

        this->traverse(root->left, depth + 1, result);
        this->traverse(root->right, depth + 1, result);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        this->traverse(root, 0, result);

        return result;
    }
};
