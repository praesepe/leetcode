class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums1) == len(nums2) == 0:
            return None
        
        if len(nums2) < len(nums1):
            nums1, nums2 = nums2, nums1
            
        l1, l2 = len(nums1), len(nums2)
        
        if l1 == 0:
            return (nums2[(l2-1)//2] + nums2[l2//2]) / 2
        
        i1_min, i1_max, middle = 0, l1, (l1+l2) // 2
        
        while i1_min < i1_max:
            i1 = (i1_min + i1_max) // 2
            i2 = middle - i1
            
            if i1 > 0 and nums1[i1-1] > nums2[i2]:
                i1_max = i1 - 1
            elif i2 > 0 and nums1[i1] < nums2[i2-1]:
                i1_min = i1 + 1
            else:
                break

        i1 = (i1_min + i1_max) // 2
        i2 = middle - i1
        
        if i1 == 0:
            median_left = nums2[i2-1]
        elif i2 == 0:
            median_left = nums1[i1-1]
        else:
            median_left = max(nums1[i1-1], nums2[i2-1])
            
        if i1 == l1:
            median_right = nums2[i2]
        elif i2 == l2:
            median_right = nums1[i1]
        else:
            median_right = min(nums2[i2], nums1[i1])
            
        return median_right if (l1+l2) % 2 == 1 else (median_left + median_right) / 2
