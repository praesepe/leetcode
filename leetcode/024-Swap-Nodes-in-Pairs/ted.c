/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *answer, *prev, *tmp;
    
    if (!head || !head->next) {
        return head;
    }
    
    answer = head->next;
    prev = head;
    
    head = answer->next;
    answer->next = prev;
    while (head && head->next) {
        prev->next = head->next;
        tmp = head->next;
        prev = head;
        head = tmp->next;
        tmp->next = prev;
    }
    
    prev->next = head;
    
    return answer;
}
