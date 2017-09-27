class Solution {
public:
    string tree2str(TreeNode* t) {
        if (t == NULL) {
            return "";
        }

        string s = to_string(t->val);

        // leaf node
        if (t->left == NULL && t->right == NULL) {
            return s;
        }

        // left child node exist
        if (t->left) {
            s += "(" + tree2str(t->left) + ")";
        // left child node doesn't exist
        } else {
            s += "()";
        }

        // right child node exist
        if (t->right) {
            s += "(" + tree2str(t->right) + ")";
        }

        return s;
    }
};

