class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        ListNode *p = NULL, *q = head, *r = head->next;
        while (r != NULL) {
            q->next = p;

            p = q;
            q = r;
            r = q->next;
        }
        q->next = p;

        return q;
    }
};
