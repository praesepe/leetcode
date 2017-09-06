#!/usr/bin/env python3
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class BSTIterator(object):
    _generator = None
    _following = None

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self._generator = self.walk(root)

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.following is not None

    def next(self):
        """
        :rtype: int
        """
        val = self.following
        self._following = None
        return val

    @property
    def following(self):
        if not self._following:
            try:
                self._following = next(self._generator)
            except StopIteration:
                pass
        return self._following

    def walk(self, node):
        if node is None:
            return
        print(node.val)
        yield from self.walk(node.left)
        yield node.val
        yield from self.walk(node.right)


if __name__ == '__main__':
    a = TreeNode(3)
    b = TreeNode(4)
    c = TreeNode(5)
    d = TreeNode(6)
    e = TreeNode(7)

    c.right = e
    e.left = d
    c.left = b
    b.left = a

    i, v = BSTIterator(c), []
    while i.hasNext():
        v.append(i.next())
    pprint(v)
