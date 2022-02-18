"""
author: L
date: 2022/2/18 21:41
"""
class Solution:
    def isPalindrome(self, x: int) -> bool:
        temp = str(x)
        return temp == temp[::-1]
