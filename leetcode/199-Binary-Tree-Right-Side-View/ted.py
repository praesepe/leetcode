# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightFirstTraverse(self, node, level_current):
        if not node:
            return
        
        if level_current > len(self.rightSideViews):
            self.rightSideViews.append(node.val)
        
        node.right and self.rightFirstTraverse(node.right, level_current+1)
        node.left and self.rightFirstTraverse(node.left, level_current+1)
    
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.rightSideViews = []
        self.rightFirstTraverse(root, 1)
        
        return self.rightSideViews
        
