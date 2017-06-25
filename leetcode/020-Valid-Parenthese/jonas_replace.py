#!/usr/bin/env python
class Solution(object):
    def isValid(self, s):
        length = 0
        while length != len(s):
            length = len(s)
            s = s.replace("()", "").replace("[]", "").replace("{}", "")
        return not s
