import os
import io

# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        def isBadVersion(version):
            if(version >= 2):
                return True
            else:
                return False
        if(isBadVersion(1) or n == 1):
            return 1
        i = n//2
        upp = n
        low = 1
        while(i >= 1):
            result = isBadVersion(i)
            #print(i,result)
            if(not result):
                if(upp - i == 1):
                    return upp
                else:
                    low = i
                    i = (upp-i)//2 + i
            else:
                if(i - low == 1):
                    return i
                else:
                    upp = i
                    i = (i-low)//2 + low

x = Solution()
a = 3
print(x.firstBadVersion(a))




