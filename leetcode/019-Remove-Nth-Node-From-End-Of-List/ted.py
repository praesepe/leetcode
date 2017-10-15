# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        tail = head
        for i in range(0, n-1):
            tail = tail.next
        
        node, prev = head, None
        while tail.next:
            tail = tail.next
            node, prev = node.next, node
            
        if prev:
            prev.next = node.next
            
        return head if node != head else node.next
