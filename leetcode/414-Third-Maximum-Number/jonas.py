#!/usr/bin/env python
import pytest
import bisect


class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = []
        for n in nums:
            if n in a:
                continue
            elif len(a) < 3:
                bisect.insort(a, n)
            else:
                loc = bisect.bisect_left(a, n)
                if loc != 0:
                    a.insert(loc, n)
                    a = a[1:4]
        return a[0] if len(a) == 3 else a[-1]


@pytest.fixture
def sol():
    return Solution()


@pytest.mark.parametrize("nums, expected", [
    ([3, 2, 1], 1),
    ([1, 2], 2),
    ([2, 2, 3, 1], 1),
    ([1, 2, 2, 5, 3, 5], 2),
])
def test_solution(sol, nums, expected):
    assert sol.thirdMax(nums) == expected
