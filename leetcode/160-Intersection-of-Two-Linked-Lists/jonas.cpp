class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* m = headA;
        ListNode* n = headB;

        if (!m || !n) {
            return NULL;
        }

        while (m && n && m != n) {
            m = m->next;
            n = n->next;

            if (!m && !n) {
                break;
            }

            if (!m) {
                m = headB;
            }
            if (!n) {
                n = headA;
            }
        }
        return m;
    }
};
