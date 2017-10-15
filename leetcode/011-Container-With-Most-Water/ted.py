class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l, r, max_ = 0, len(height)-1, 0
        
        while l < r:
            max_ =  max(max_, (r-l)*min(height[r], height[l]))
            if height[r] < height[l]:
                r -= 1
            else:
                l += 1
            
        return max_
