/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head,*cur;
        int sum,reminder,carry;
        sum = reminder = carry = 0;
        head = cur = new ListNode(0);
        
        
        while(l1 != NULL || l2 != NULL){
            sum = carry + ((l1==NULL)?0:l1->val)+((l2==NULL)?0:l2->val);
            reminder = sum % 10;
            carry = sum / 10;
            cur = cur->next = new ListNode(reminder);
            l1 = (l1==NULL) ? NULL:l1->next;
            l2 = (l2==NULL) ? NULL:l2->next;
        }
        
        if(carry != 0){
            cur->next = new ListNode(carry);
        }
        return head->next; 
    }
};

