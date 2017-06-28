
class Solution(object):
    def maxSubArray(self, nums):
        global_max = local_max = nums[0]
        for i in nums[1:]:
            if(local_max + i < i):
                local_max = i
            else:
                local_max += i
            if(local_max > global_max):
                global_max = local_max
        return global_max
                      
x = Solution()
a = [-2,1,-3,4,-1,2,1,-5,4]
print(x.maxSubArray(a))



