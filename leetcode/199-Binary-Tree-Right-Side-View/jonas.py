#!/usr/bin/env python
import collections

Node = collections.namedtuple('Node', ['level', 'val'])


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        for node in self.traverse(root, 1):
            if node.level <= len(result):
                continue
            result.append(node.val)
        return result

    def traverse(self, root, level):
        if root is None:
            return
        yield Node(level, root.val)
        for node in self.traverse(root.right, level + 1):
            yield node
        for node in self.traverse(root.left, level + 1):
            yield node
