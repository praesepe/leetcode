class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        positives = {}
        negatives = {}
        zeros = 0
        for num in nums:
            if num == 0:
                zeros += 1
            elif num > 0:
                positives[num] = positives.get(num, 0) + 1
            else:
                negatives[num] = negatives.get(num, 0) + 1
                
        ans = []
        
        if zeros >= 3:
            ans.append([0,0,0])
        
        if zeros >= 1:
            for num in positives.keys():
                if -num in negatives:
                    ans.append([num,0,-num])
                    
        for num in positives.keys():
            for num2 in positives.keys():
                if num < num2 or (num == num2 and positives[num] < 2):
                    continue
                
                neg = (num + num2) * -1
                if neg in negatives:
                    ans.append([num, num2, neg])
                    
        for num in negatives.keys():
            for num2 in negatives.keys():
                if num < num2 or (num == num2 and negatives[num] < 2):
                    continue
                    
                pos = (num + num2) * -1
                if pos in positives:
                    ans.append([pos, num, num2])
                    
        return ans
        
