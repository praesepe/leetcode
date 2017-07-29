class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """

        left = 0
        right = 0

        for c in s:
            if c == '(':
                left += 1
            elif c == ')':
                if left > 0:
                    left -= 1
                else:
                    right += 1
        return self.solve(s, "", left, right, 0, 0)

    def solve(self, s, result, left, right, pivot, diff):
        """solve

        :param s: the original string
        :type s: str
        :param s: the modified string
        :type s: str
        :param left: the number of left bracket needs to be removed
        :type left: int
        :param right: the number of right bracket needs to be removed
        :type right: int
        :param pivot: the index of string of current search
        :type pivot: int
        :param diff: the diff between left and right bracket from 0 to pivot
        :type diff: int

        :rtype: List[str]
        """

        if len(s) == pivot and all(v == 0 for v in (left, right, diff)):
            return [result]
        if len(s) <= pivot or any(v < 0 for v in (left, right, diff)):
            return []

        answer = []
        if s[pivot] == '(':
            answer += self.solve(s, result+'(', left, right, pivot+1, diff+1)
            answer += self.solve(s, result, left-1, right, pivot+1, diff)
        elif s[pivot] == ')':
            answer += self.solve(s, result+')', left, right, pivot+1, diff-1)
            answer += self.solve(s, result, left, right-1, pivot+1, diff)
        else:
            answer += self.solve(s, result + s[pivot], left, right, pivot + 1,
                                 diff)

        return list(set(answer))
