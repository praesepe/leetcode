class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows <= 1:
            return s
        
        len_ = len(s)
        cycle_len = 2*numRows - 2
        
        zs, zs_idx = bytearray(len_), 0
        for i in range(0, numRows):
            idx, gap_idx, gaps = i, 0, filter(None, [cycle_len - 2*i, 2*i])
            
            gaps_len = len(gaps)
            while idx < len_:
                zs[zs_idx] = ord(s[idx]) 
                idx, gap_idx, zs_idx = idx+gaps[gap_idx], (gap_idx+1) % gaps_len, zs_idx+1
        
        return zs.decode('ascii')
