# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.count = k
        self.answer = None
        self.dfs(root)
        
        return self.answer
        
    def dfs(self, node):
        if node.left:
            self.dfs(node.left)
        
        self.count -= 1
        if self.count == 0:
            self.answer = node.val
            return
        
        if node.right:
            self.dfs(node.right)
