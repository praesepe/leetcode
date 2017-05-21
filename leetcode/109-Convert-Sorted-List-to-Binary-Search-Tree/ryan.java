public class Solution {
    public TreeNode sortedListToBST(List<ListNode> list, int start, int end) {
        if(start > end) {
            return null;
        }
        int middle = (start + end) / 2;
        TreeNode tn = new TreeNode(list.get(middle).val);
        tn.left = sortedListToBST(list, start, middle - 1);
        tn.right = sortedListToBST(list, middle + 1, end);
        return tn;
    }

    public TreeNode sortedListToBST(ListNode head) {
        if(head == null) {
            return null;
        }
        List<ListNode> list = new ArrayList();
        while (head != null) {
            list.add(head);
            head = head.next;
        }

        return sortedListToBST(list, 0, list.size() - 1);
    }
}