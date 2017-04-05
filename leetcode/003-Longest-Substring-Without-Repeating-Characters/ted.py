class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        char_idx_map = dict()
        
        substr_start_idx = 0
        max_substr_len = 0
        
        for idx, char in enumerate(s):
            repeat_idx = char_idx_map.get(char, -1)
            
            if repeat_idx >= substr_start_idx:
                max_substr_len = max(max_substr_len, idx-substr_start_idx)
                substr_start_idx = repeat_idx + 1
            
            char_idx_map[char] = idx
            
        return max(max_substr_len, len(s)-substr_start_idx)
