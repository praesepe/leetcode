class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        lp_start, lp_len = 0, 0
        i, max_idx = 0, len(s) - 1
        while i <= max_idx:
            if (max_idx - i) * 2 + 1 <= lp_len:
                break

            start = end = i
            
            while end < max_idx and s[end] == s[end+1]:
                end += 1
            i = end + 1
            
            while start > 0 and end < max_idx and s[start-1] == s[end+1]:
                start -= 1
                end += 1
            
            if end - start + 1 > lp_len:
                lp_start, lp_len = start, end - start + 1
        
        return s[lp_start:lp_start+lp_len]
