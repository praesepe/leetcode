class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode *p = headA, *q = headB;
        while (p != q) {
            p = p->next;
            q = q->next;

            // Any time they collide or reach end together without colliding
            // then return any one of the pointers.
            if (p == q) {
                break;
            }

            // If one of them reaches the end earlier then reuse it
            // by moving it to the beginning of other list.
            // Once both of them go through reassigning,
            // they will be equidistant from the collision point.
            if (p == NULL) {
                p = headA;
            }
            if (q == NULL) {
                q = headB;
            }
        }

        return p;
    }
};

