class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        // find center node
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        // move to next node if head size is odd
        if (fast != null) {
            slow = slow.next;
        }
        slow = reverse(slow);
        fast = head;
        while (slow != null) {
            if(slow.val != fast.val) {
                return false;
            }
            slow = slow.next;
            fast = fast.next;
        }
        return true;
    }

    private ListNode reverse(ListNode head) {
        ListNode pre = null;
        ListNode next;
        while (head != null) {
            next = head.next;
            head.next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
}