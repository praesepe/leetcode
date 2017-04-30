struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head, *prev, *curr;
    
    if (!l1) {
        return l2;
    }
    
    if (!l2) {
        return l1;
    }
    
    head = l1->val <= l2->val ? l1 : l2;
    prev = head;
    
    while (prev && l1 && l2) {
        if (l1->val <= l2->val) {
            curr = l1;
            l1 = l1->next;
        } else {
            curr = l2;
            l2 = l2->next;
        }
        
        prev->next = curr;
        prev = curr;
    }

    if (prev) {
        prev->next = l1 ? l1 : l2;
    }
    
    return head;
}
