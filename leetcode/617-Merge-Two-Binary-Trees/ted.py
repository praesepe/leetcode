# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def dfsTraverse(self, node1, node2):
        if not node1:
            return node2
        
        if not node2:
            return node1
        
        mergedNode = TreeNode(node1.val + node2.val)
        mergedNode.left = self.dfsTraverse(node1.left, node2.left)
        mergedNode.right = self.dfsTraverse(node1.right, node2.right)
        
        return mergedNode
    
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        return self.dfsTraverse(t1, t2)
        
