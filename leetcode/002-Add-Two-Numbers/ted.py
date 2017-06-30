# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Number(object):
    def __init__(self, listNode):
        self.head = listNode
        
    def nextDigit(self):
        val = 0
        
        if self.head:
           val = self.head.val
           self.head = self.head.next
           
        return val
        
    def hasMoreDigit(self):
        return self.head != None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        l1, l2 = Number(l1), Number(l2)
        extra, prevNode, headNode = 0, None, None
        
        while l1.hasMoreDigit() or l2.hasMoreDigit() or extra:
            sum = l1.nextDigit() + l2.nextDigit() + extra
            digit = (sum % 10)
            extra = sum / 10
            
            currentNode = ListNode(digit)
            
            if prevNode:
                prevNode.next = currentNode
            else:
                headNode = currentNode

            prevNode = currentNode
                
        return headNode

        
