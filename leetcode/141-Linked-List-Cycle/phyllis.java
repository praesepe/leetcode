/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null || head.next == null) return false;
        ListNode hare, tortoise;
        hare = tortoise = head;
        while(hare != null){
            hare = hare == null ? null : hare.next;
            hare = hare == null ? null : hare.next;
            tortoise = tortoise.next;
            
            if(hare != null && hare.val == tortoise.val)
                return true;
        }
        
        return false;
    }
}
