class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = getLength(headA);
        int n = getLength(headB);
        if (m < n) {
            return getIntersectionNode(headB, headA);
        }

        // headA move k steps first
        int k = m - n;
        for (int i = 0; i < k; i++) {
            headA = headA->next;
        }

        // headA and headB move togather
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
private:
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }
        return len;
    }
};

