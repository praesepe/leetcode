# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.peek = None
        self.iterator = traverse(root)
        

    def hasNext(self):
        """
        :rtype: bool
        """
        
        try:
            self.peek = self.peek if self.peek != None else next(self.iterator)
            return True
        except:
            return False

    def next(self):
        """
        :rtype: int
        """
        
        try:
            val = self.peek if self.peek != None else next(self.iterator)
            self.peek = None
            return val
        except:
            return None
        
def traverse(node):
    if node:
        for val in traverse(node.left):
            yield val
        yield node.val
        for val in traverse(node.right):
            yield val  
        

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
