"""
author: L
date: 2022/2/23 23:07
"""

class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        ans = []
        for i in s:
            if (i >= 'a' and i <= 'z') or (i >= 'A' and i <= 'Z'):
                ans.append(i)

        ans = ans[::-1]
        j = 0
        val = ""
        for i in s:
            if (i >= 'a' and i <= 'z') or (i >= 'A' and i <= 'Z'):
                val += ans[j]
                j += 1
            else:
                val += i

        return val
