class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum([n for idx, n in enumerate(sorted(nums)) if idx%2 == 0]) 
