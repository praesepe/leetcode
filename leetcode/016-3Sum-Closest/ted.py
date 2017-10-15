class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) < 3:
            return None
        
        nums = sorted(nums)
        
        min_diff = nums[0] + nums[1] + nums[2] - target
        
        for i1 in range(0, len(nums)-2):
            i2, i3 = i1+1, len(nums)-1
            while i2 < i3:
                diff = nums[i1] + nums[i2] + nums[i3] - target
                if diff == 0:
                    return target
                min_diff = diff if abs(diff) < abs(min_diff) else min_diff
                if diff < 0:
                    i2 += 1
                else:
                    i3 -= 1
                
        return target + min_diff
