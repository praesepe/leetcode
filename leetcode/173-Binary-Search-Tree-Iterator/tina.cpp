class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        node = root;
        
        pushNodes();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodes.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *curNode = nodes.back();
        
        nodes.pop_back();
        node = curNode->right;
        
        pushNodes();
        
        return curNode->val;
    }
    
private:
    void pushNodes() {
        while (node != NULL) {
            nodes.push_back(node);
            node = node->left;
        }
    }
    
    TreeNode *node;
    vector<TreeNode*> nodes;
};
