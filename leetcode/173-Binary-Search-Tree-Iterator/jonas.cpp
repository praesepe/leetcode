class BSTIterator {
 protected:
    std::stack<TreeNode*> stack_;

    void traverse(TreeNode* node) {
        while (node) {
            this->stack_.push(node);
            node = node->left;
        }
    }

 public:
    explicit BSTIterator(TreeNode *root) {
        this->traverse(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !this->stack_.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* current = this->stack_.top();
        this->stack_.pop();

        this->traverse(current->right);
        return current->val;
    }
};
