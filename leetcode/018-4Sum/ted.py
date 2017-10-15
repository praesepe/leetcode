class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if len(nums) < 4:
            return []
        
        nums, ans, l = sorted(nums), [], len(nums)
        
        for i1 in range(0, l-3):
            if i1 > 0 and nums[i1] == nums[i1-1]:
                continue

            for i2 in range(i1+1, l-2):
                if i2 > i1+1 and nums[i2] == nums[i2-1]:
                    continue
                
                i3, i4 = i2+1, l-1
                while i3 < i4:
                    diff = nums[i1] + nums[i2] + nums[i3] + nums[i4] - target
                    if diff == 0:
                        ans.append([nums[i1],nums[i2],nums[i3],nums[i4]])
                        while i3 < i4 and nums[i3] == nums[i3+1]:
                            i3 += 1
                        while i3 < i4 and nums[i4] == nums[i4-1]:
                            i4 -= 1
                        i3, i4 = i3+1, i4-1
                    elif diff > 0:
                        i4 -= 1
                    else:
                        i3 += 1
                        
        return ans
