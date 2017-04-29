class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = head;
        ListNode *prev = &dummy;

        while (p != NULL && p->next != NULL) {
            ListNode *q = p->next, *r = p->next->next;
            prev->next = q;
            q->next = p;
            p->next = r;
            prev = p;
            p = r;
        }

        return dummy.next;
    }
};
