class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        
        write_cnt = 1
        for read_idx in range(1, len(nums)):
            if nums[read_idx] != nums[read_idx-1]:
                nums[write_cnt] = nums[read_idx]
                write_cnt += 1
        
        return write_cnt
