#!/usr/bin/env python3
import pytest
import collections

Node = collections.namedtuple('Node', 'node level order')


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def widthOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        starts = []
        node = Node(node=root, level=0, order=1)
        return max(self.dfs(node, starts))

    def dfs(self, node, starts):
        if node.node is None:
            return 0

        if len(starts) == node.level:
            starts.append(node.order)

        yield node.order - starts[node.level] + 1

        left = Node(
            node=node.node.left,
            level=node.level + 1,
            order=node.order * 2)
        yield from self.dfs(left, starts)

        right = Node(
            node=node.node.right,
            level=node.level + 1,
            order=node.order * 2 + 1)
        yield from self.dfs(right, starts)


@pytest.fixture
def sol():
    return Solution()


def test_solution1(sol):
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(4)
    e = TreeNode(5)
    f = TreeNode(6)

    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.right = f

    assert sol.widthOfBinaryTree(a) == 4


def test_solution2(sol):
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(4)

    a.left = b
    b.left = c
    b.right = d

    assert sol.widthOfBinaryTree(a) == 2


def test_solution3(sol):
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(4)

    a.left = b
    a.right = c
    b.left = d

    assert sol.widthOfBinaryTree(a) == 2


def test_solution4(sol):
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(4)
    e = TreeNode(5)
    f = TreeNode(6)
    g = TreeNode(7)

    a.left = b
    a.right = c
    b.left = d
    d.left = e
    c.right = f
    f.right = g

    assert sol.widthOfBinaryTree(a) == 8
