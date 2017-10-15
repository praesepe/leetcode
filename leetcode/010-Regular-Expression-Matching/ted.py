class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        m = [[False for idx_p in range(0, len(p)+1)] for idx_s in range(0, len(s)+1)]
        
        m[0][0] = True
        for idx_p in range(2,len(p)+1):
            m[0][idx_p] = (p[idx_p-1] == '*' and m[0][idx_p-2])
            
        for idx_s in range(1, len(s)+1):
            for idx_p in range(1, len(p)+1):
                if p[idx_p-1] == '*':
                    m[idx_s][idx_p] = m[idx_s][idx_p-2] or (m[idx_s-1][idx_p] and (p[idx_p-2] == '.' or p[idx_p-2] == s[idx_s-1]))
                else:
                    m[idx_s][idx_p] = m[idx_s-1][idx_p-1] and (p[idx_p-1] == s[idx_s-1] or p[idx_p-1] == '.')
        
        return m[len(s)][len(p)]
