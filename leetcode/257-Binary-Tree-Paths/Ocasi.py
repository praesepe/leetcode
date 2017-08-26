import os
import io

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        try:
            result = []#record for output result, format like ["1->2->3","1->5"]
            if(root.val != "" and root.left == None and root.right == None):
                return ["1"]
            while(root.left != None or root.right != None):
                current = []
                current.append(''.join(str(root.val)))
                leaf = root
                trace_mark = 0
                i = 0
                while(leaf.left != None or leaf.right != None):
                    if(leaf.left != None):
                        if(leaf.right != None):
                            trace_mark = i
                        leaf = leaf.left
                    else:
                        leaf = leaf.right
                    current.append(str(leaf.val))
                    i += 1
                result.append("->".join(current))
                leaf = root
                for i in range(trace_mark+1):
                    if(leaf.left != None):
                        if(i == trace_mark):
                            leaf.left = None
                        leaf = leaf.left
                    else:
                        if(i == trace_mark):
                            leaf.right = None
                        leaf = leaf.right
            return result           
        except AttributeError:
            return []
            
            
x = Solution()
a = TreeNode(1)
a.left = TreeNode(2)
a.right = TreeNode(3)
a.left.right = TreeNode(5)
#print(a.val, a.left.val, a.right.val, a.left.right.val, a.left.right.right)
print(x.binaryTreePaths(a))
a = TreeNode("")
print(x.binaryTreePaths(a))
a = TreeNode(1)
print(x.binaryTreePaths(a))


