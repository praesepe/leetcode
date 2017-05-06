public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) {
            return null;
        }

        ListNode result = new ListNode(0);
        ListNode resultPointer = result;

        int tenDigits = 0;
        while (l1 != null && l2 != null) {
            int digits = l1.val + l2.val + tenDigits;
            tenDigits = digits / 10;
            digits %= 10;

            resultPointer.next = new ListNode(digits);
            l1 = l1.next;
            l2 = l2.next;
            resultPointer = resultPointer.next;
        }

        ListNode last = l1 == null ? l2 : l1;
        while (last != null) {
            int digits = last.val + tenDigits;
            tenDigits = digits / 10;
            digits %= 10;
            resultPointer.next = new ListNode(digits);
            resultPointer = resultPointer.next;
            last = last.next;
        }

        if (tenDigits != 0) {
            System.out.println(tenDigits);
            resultPointer.next = new ListNode(tenDigits);
        }

        return result.next;
    }
}
