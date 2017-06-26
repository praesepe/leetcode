
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        index_l = 0
        index_u = len(nums)-1
        while(1):
            if(target <= nums[index_l]):
                return index_l
            if(target == nums[index_u]):
                return index_u
            if(target > nums[index_u]):
                return index_u+1
            index_m = int(index_l + (index_u-index_l+1)/2)
            if(target < nums[index_m]):
                index_u = index_m -1
            elif(target > nums[index_m]):
                index_l = index_m +1
            else:
                return index_m
        
            
x = Solution()
a = [1,3]
print(x.searchInsert(a,3))





