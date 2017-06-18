# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.max = None
        self.maxToRoot(root)
        
        if not self.max:
            self.max = 0
            
        return self.max
        
    def maxToRoot(self, node):
        if not node:
            return 0
            
        l = self.maxToRoot(node.left)
        r = self.maxToRoot(node.right)
        
        answer = node.val
        
        if l > 0:
            answer += l
            
        if r > 0:
            answer += r
            
        if self.max == None or self.max < answer:
            self.max = answer
            
        return node.val + max(0, l, r)
        
