public class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode newHead = head.next;
        head.next = swapPairs(head.next.next);
        newHead.next = head;

        return newHead;
    }
	
    public ListNode swapPairs2(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode current = dummy, first, second;
        while (current.next != null && current.next.next != null) {
            first = current.next;
            second = current.next.next;
            first.next = current.next.next.next;
            current.next = second;
            current.next.next = first;
            current = current.next.next;
        }

        return dummy.next;
    }
}