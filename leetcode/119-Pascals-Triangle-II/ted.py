class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        k = rowIndex + 1
        if k <= 0:
            return []
        
        pascals = [1]
        middle_idx = k//2 + k%2
        for i in range(1, middle_idx):
            pascals.append(pascals[i-1] * (k-i) / i)
        
        copy_idx = middle_idx - 1 - k%2
        if copy_idx >= 0:
            pascals.extend(pascals[copy_idx::-1])
            
        return pascals
