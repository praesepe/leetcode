#!/usr/bin/env python
import pytest


class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        for n in nums:
            if count == 0:
                major = n
                count += 1
            elif n == major:
                count += 1
            else:
                count -= 1
        return major


@pytest.fixture
def sol():
    return Solution()


@pytest.mark.parametrize("nums, expected", [
    ([1, 2, 1, 3, 4, 1, 1], 1),
    ([1], 1),
    ([2, 1, 1], 1),
    ([2, 2, 1, 1, 1], 1)
])
def test_solution(sol, nums, expected):
    assert sol.majorityElement(nums) == expected
