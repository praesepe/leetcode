public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) {
            return null;
        }

        ListNode result = new ListNode(0);
        ListNode resultPointer = result;

        int tenDigits = 0;
        while (l1 != null || l2 != null) {
            int l1Val = l1 == null ? 0 : l1.val;
            int l2Val = l2 == null ? 0 : l2.val;
            int digits = l1Val + l2Val + tenDigits;
            tenDigits = digits / 10;
            digits %= 10;

            resultPointer.next = new ListNode(digits);
            l1 = l1 == null ? null : l1.next;
            l2 = l2 == null ? null : l2.next;
            resultPointer = resultPointer.next;
        }

        if (tenDigits != 0) {
            resultPointer.next = new ListNode(tenDigits);
        }

        return result.next;
    }
}
