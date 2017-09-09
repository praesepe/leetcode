#!/usr/bin/env python
import pytest


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        return ','.join(self._serialize(root))

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        return self._deserialize(iter(data.split(',')))

    def _serialize(self, root):
        if root is None:
            yield '-'
        else:
            yield str(root.val)
            for val in self._serialize(root.left):
                yield str(val)
            for val in self._serialize(root.right):
                yield str(val)

    def _deserialize(self, data):
        val = next(data)
        if val == '-':
            return None

        t = TreeNode(int(val))
        t.left = self._deserialize(data)
        t.right = self._deserialize(data)
        return t


@pytest.fixture
def codec():
    return Codec()


def test_codec(codec):
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(4)
    e = TreeNode(5)
    f = TreeNode(6)
    g = TreeNode(7)
    h = TreeNode(8)
    i = TreeNode(9)

    a.left = b
    a.right = c
    b.left = d
    b.right = e
    e.left = h
    h.right = i
    c.right = f
    f.left = g

    code = '1,2,4,-,-,5,8,-,9,-,-,-,3,-,6,7,-,-,-'
    assert codec.serialize(a) == code
    root = codec.deserialize(code)
    compare(root, a)


@pytest.mark.parametrize("tree, code", [
    (TreeNode(1), '1,-,-'),
    (None, '-'),
])
def test_edge(codec, tree, code):
    assert codec.serialize(tree) == code
    compare(codec.deserialize(code), tree)


def compare(t1, t2):
    if t1 is None:
        assert t2 is None
        return
    assert t1.val == t2.val
    compare(t1.left, t2.left)
    compare(t1.right, t2.right)
