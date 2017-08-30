#include <stack>

using namespace std;

/**
 * Definition for binary tree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    void walk(TreeNode *root) {
        this->s.pop();

        while (root) {
            this->s.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        // initialize
        this->s.push(NULL);
        this->walk(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* root = s.top();
        int result = root->val;
        this->walk(root->right);

        return result;
    }
private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
