class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        if (prev) {
            prev->next = NULL;
        } else {
            head = NULL;
        }

        TreeNode* node = new TreeNode(slow->val);
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(slow->next);

        return node;
    }
};

