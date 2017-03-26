class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        number_index_map = dict()
        
        for index, num in enumerate(nums):
            diff_idx = number_index_map.get(target - num)
            if diff_idx is not None:
                return [diff_idx, index]
            
            number_index_map[num] = index
            
        return []
