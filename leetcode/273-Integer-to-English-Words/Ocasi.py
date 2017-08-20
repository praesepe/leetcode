import os
import io
  
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        summary = []
        nums.sort()
        for i in range(len(nums)-2):
            if(i == 0 or nums[i] != nums[i-1]):
                low_b = i+1
                up_b = len(nums)-1
                while(up_b > low_b):
                    x_sum = nums[i] + nums[low_b] + nums[up_b]
                    if(x_sum <= 0):
                        if(x_sum == 0):
                            summary.append((nums[i], nums[low_b], nums[up_b]))
                        low_b += 1
                        while(nums[low_b] == nums[low_b-1] and low_b != up_b):
                            low_b += 1
                    else:
                        up_b -= 1
                        while(nums[up_b] == nums[up_b+1] and up_b != low_b):
                            up_b -= 1 
        return summary
        

            
x = Solution()
a = [-1, 0, 1, 2, -1, -4]
print(x.threeSum(a))
a = [-3, -2, -2, -2, -1, -1, 0, 1, 1, 1, 2, -1, -4, 5, 6]
print(x.threeSum(a))
a = [0,0,0]
print(x.threeSum(a))




