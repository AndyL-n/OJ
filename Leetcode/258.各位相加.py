"""
author: L
date: 2022/3/3 22:34
"""
class Solution:
    def addDigits(self, num: int) -> int:
        ans = 0
        while(1):
            while(num > 0):
                ans += num % 10
                num //= 10
            if len(str(ans)) == 1:
                break
            num = ans
            ans = 0
        return ans