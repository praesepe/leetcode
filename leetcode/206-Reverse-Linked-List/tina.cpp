class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *node = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        
        while (node != NULL) {
            next = node->next;
            node->next = prev;
            
            prev = node;
            node = next;
        }
        
        return prev;
    }
};
