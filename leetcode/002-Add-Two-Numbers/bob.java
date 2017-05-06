public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) {
            return null;
        }

        ListNode temp = new ListNode(0);
        ListNode result = temp;

        int tenDigits = 0;
        while (l1 != null && l2 != null) {
            int digits = l1.val + l2.val + tenDigits;
            tenDigits = digits / 10;
            digits %= 10;

            result.next = new ListNode(digits);
            l1 = l1.next;
            l2 = l2.next;
            result = result.next;
        }

        ListNode last = l1 == null ? l2 : l1;
        while (last != null) {
            int digits = last.val + result.val + tenDigits;
            tenDigits = digits / 10;
            digits %= 10;
            result.next = new ListNode(digits);
        }

        if (tenDigits != 0) {
            result.next = new ListNode(tenDigits);
        }

        return temp.next;
    }
}
