class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i, len_ = 0, len(nums)
        while i < len_:
            if nums[i] == val:
                len_ -= 1
                nums[i], nums[len_] = nums[len_], nums[i]
            else:
                i += 1
                
        return len_
