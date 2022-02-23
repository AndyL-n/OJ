"""
author: L
date: 2022/2/23 23:17
"""

class Solution:
    def myPow(self, x: float, n: int) -> float:
        flag = n
        n = n if n >= 0 else (-n)
        ans = 1
        while(n):
            if n&1:
                ans *= x
            x *= x
            n >>=1
        return ans if flag >= 0 else 1.0/ans
    