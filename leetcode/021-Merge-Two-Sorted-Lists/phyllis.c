/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  
    struct ListNode  dummyNode = {0, NULL};
    struct ListNode  *current = &dummyNode; 
   
    // to sort nodes
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            current -> next = l1;
            l1 = l1->next;
        }else{
            current -> next = l2;
            l2 = l2->next;
        }
            current = current -> next;
    }
    
    // to append list
    current -> next = l1 ? l1:l2;
   
    return dummyNode.next;
}

