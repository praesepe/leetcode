public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0) {
            return null;
        }
        
        PriorityQueue<ListNode> pq = new PriorityQueue(lists.length, new Comparator<ListNode>() {
            @Override
            public int compare(ListNode o1, ListNode o2) {
                return o1.val - o2.val;
            }
        });
        
        // add first elements for each ListNode
        for(ListNode ln : lists) {
            if(ln != null) {
                pq.add(ln);
            }
        }
        ListNode result = new ListNode(0);
        ListNode dummy = result;
        while(!pq.isEmpty()) {
            dummy.next = pq.poll();
            dummy = dummy.next;
            if(dummy.next != null) {
                pq.add(dummy.next);
            }
        }
        return result.next;
    }
}