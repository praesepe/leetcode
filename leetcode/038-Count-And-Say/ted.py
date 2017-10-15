class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n <= 0:
            return ""
        
        say = "1"
        for i in range(1, n):
            next_say, cnt = [], 1
            for j in range(0, len(say)-1):
                if say[j] == say[j+1]:
                    cnt += 1
                else:
                    next_say.extend([str(cnt), say[j]])
                    cnt = 1
            next_say.extend([str(cnt), say[len(say)-1]])
            say = "".join(next_say)
        
        return say
