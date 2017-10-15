class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        
        if len(strs) == 1:
            return strs[0]
        
        min_length, max_prefix = min(map(len, strs)), 0
        
        for i in range(0, min_length):
            for j in range(1, len(strs)):
                if strs[0][i] != strs[j][i]:
                    return strs[0][0:max_prefix]
            max_prefix += 1
        
        return strs[0][0:max_prefix]
