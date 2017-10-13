class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        xor_complete, xor_missing = len(nums), 0
        
        for idx, num in enumerate(nums):
            xor_complete ^= idx
            xor_missing ^= num
            
        return xor_complete ^ xor_missing 
