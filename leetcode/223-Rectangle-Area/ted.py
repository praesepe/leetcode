class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        lower_x = A if A > E else E
        lower_y = B if B > F else F
        upper_x = C if C < G else G
        upper_y = D if D < H else H
        
        no_overlap = lower_x >= upper_x or lower_y >= upper_y
        overlap_area = 0 if no_overlap else (upper_x - lower_x) * (upper_y - lower_y)
        
        return (C-A)*(D-B) + (G-E)*(H-F) - overlap_area
