class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        
        while (nodeA != NULL && nodeB != NULL && nodeA != nodeB) {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
            
            if (nodeA == nodeB) return nodeA;
            
            if (nodeA == NULL) nodeA = headB;
            if (nodeB == NULL) nodeB = headA;
        }
        
        return nodeA;
    }
};
