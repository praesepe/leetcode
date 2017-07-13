
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        local_min_prod = local_max_prod = max_prod = min_prod = nums[0]
        for i in nums[1:]:
            if(i < 0):
                local_min_prod, local_max_prod = local_max_prod, local_min_prod

            local_max_prod = max(i, local_max_prod * i)
            local_min_prod = min(i, local_min_prod * i)
            max_prod = max(max_prod, local_max_prod)
            min_prod = max(min_prod, local_min_prod)
        return max_prod
                    
                      
x = Solution()
a = [2,3,-2,4]
print(x.maxProduct(a))
a = [-1, 2, 0, 3,-2, 4]
print(x.maxProduct(a))



