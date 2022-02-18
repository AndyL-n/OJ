"""
author: L
date: 2022/2/18 21:38
"""


class Solution:
    def reverse(self, x: int) -> int:
        flag = 0
        if x < 0:
            flag = 1
            x = -1 * x

        ans = 0
        while (x > 0):
            ans = ans * 10 + x % 10
            x = (x - x % 10) / 10

        if flag:
            ans = -ans
        if ans < -2 ** 31 or ans > 2 ** 31 - 1:
            ans = 0
        return int(ans)
