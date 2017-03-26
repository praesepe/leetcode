class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        head = 0
        tail = len(numbers) - 1
        
        while head < tail:
            if numbers[head] + numbers[tail] == target:
                return [head+1, tail+1]
                
            if numbers[head] + numbers[tail] < target:
                head += 1
                continue
            
            tail -= 1
            continue
        
        return []
