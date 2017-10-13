class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = 3
        maxs = [None] * n
        for num in nums:
            if num in maxs:
                continue
            
            for i in range(0,n):
                if maxs[i] == None or num > maxs[i]:
                    maxs.insert(i, num)
                    del maxs[n:]
                    break
                    
        return maxs[0] if None in maxs else maxs[n-1]
