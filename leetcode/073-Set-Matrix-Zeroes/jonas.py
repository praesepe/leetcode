#!/usr/bin/env python
import pytest


class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        zero_rows = set()
        zero_cols = set()
        for m, row in enumerate(matrix):
            for n, val in enumerate(row):
                if val != 0:
                    continue
                zero_rows.add(m)
                zero_cols.add(n)
        for m in zero_rows:
            for n in range(len(matrix[0])):
                matrix[m][n] = 0
        for n in zero_cols:
            for m in range(len(matrix)):
                matrix[m][n] = 0


@pytest.fixture
def sol():
    return Solution()


@pytest.mark.parametrize("matrix, expected", [
    (
        [
            [1, 2, 3, 4, 5],
            [1, 0, 3, 0, 5],
            [1, 2, 0, 4, 5],
            [1, 2, 3, 4, 5],
            [1, 2, 3, 0, 0],
        ],
        [
            [1, 0, 0, 0, 0],
            [0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0],
            [1, 0, 0, 0, 0],
            [0, 0, 0, 0, 0],
        ]
    ),
    (
        [
            [0, 1],
        ],
        [
            [0, 0],
        ]
    ),
    (
        [
            [1],
        ],
        [
            [1],
        ]
    ),
    (
        [
            [0],
        ],
        [
            [0],
        ]
    ),
])
def test_solution(sol, matrix, expected):
    sol.setZeroes(matrix)
    assert matrix == expected
