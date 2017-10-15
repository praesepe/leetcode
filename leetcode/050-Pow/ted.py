class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n < 0:
            x, n = 1.0/x, -n
            
        ans = 1
        
        while n > 0:
            if n%2:
                ans, n = ans*x, n-1
            else:
                x, n = x*x, n/2
            
        return ans
