class Solution(object):
    def rotate(self, matrix):
        matrix[:] = zip(*matrix[::-1])
