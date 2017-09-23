public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null) {
            return false;
        }
        ListNode one_step = head;
        ListNode two_step = head.next;
        while(two_step != null && two_step.next != null) {
            if(one_step == two_step) {
                return true;
            }
            one_step = one_step.next;
            two_step = two_step.next.next;
        }
        
        return false;
    }
}