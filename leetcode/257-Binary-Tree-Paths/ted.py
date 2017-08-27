# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if not root:
            return []
        
        self.answers = []
        self.traverse(root, "")
        
        return self.answers
    
    def traverse(self, node, prefix):
        if not (node.left or node.right):
            return self.answers.append(prefix + str(node.val))
        
        if node.left:
            self.traverse(node.left, prefix + str(node.val) + "->")
            
        if node.right:
            self.traverse(node.right, prefix + str(node.val) + "->")
