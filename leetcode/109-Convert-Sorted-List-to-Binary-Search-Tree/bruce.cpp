class Solution {
private:
    TreeNode *createBST(ListNode *head, ListNode *end) {
        if (head == end) {
            return NULL;
        }
        
        if (head->next == end) {
            return new TreeNode(head->val);
        }
        
        // cut in the middle
        ListNode *rootIndex = head;
        ListNode *iter = head;
        while (iter != end && iter->next != end) {
            iter = iter->next->next;
            rootIndex = rootIndex->next;
        }
        
        TreeNode *root = new TreeNode(rootIndex->val);
        root->left = createBST(head, rootIndex);
        root->right = createBST(rootIndex->next, end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return createBST(head, NULL);
    }
};
