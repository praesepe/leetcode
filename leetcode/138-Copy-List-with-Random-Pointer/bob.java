public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) {
            return head;
        }

        RandomListNode headPointer = head;

        while (headPointer != null) {
            RandomListNode current = headPointer;
            RandomListNode next = headPointer.next;

            //copy
            RandomListNode newNode = new RandomListNode(headPointer.label);

            //save pointer
            newNode.next = current.next;
            current.next = newNode;

            headPointer = next;
        }

        headPointer = head;
        while (headPointer != null) {
            RandomListNode newNode = headPointer.next;
            RandomListNode next = newNode.next;
            newNode.random = null;

            if (headPointer.random != null) {
                newNode.random = headPointer.random.next;
            }

            headPointer = next;
        }

        RandomListNode result = new RandomListNode(0);
        RandomListNode resultPointer = result;
        headPointer = head;
        while (headPointer != null) {
            RandomListNode newNode = headPointer.next;
            RandomListNode next = newNode.next;

            resultPointer.next = newNode;
            headPointer.next = next;

            resultPointer = resultPointer.next;
            headPointer = headPointer.next;
        }

        return result.next;
    }
}
