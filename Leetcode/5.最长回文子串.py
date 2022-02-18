"""
author: L
date: 2022/2/16 21:03
"""

class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans,temp = 0, ""
        for index, val in enumerate(s):
            for i in range(1, len(s)):
                if index - i < 0 or index + i >= len(s):
                    break
                if s[index - i] == s[index + i]:
                    if 2*i + 1 > ans:
                        ans = 2*i + 1
                        temp = s[index - i: index + i + 1]
                        print(s[index-i], s[index+1],index, i ,temp)
                else:
                    break

            if index + 1 < len(s) and s[index] == s[index + 1]:
                if 2 > ans:
                    ans = 2
                    temp = s[index: index + 2]
                for i in range(1, len(s)):
                    if index - i < 0 or index + i + 1>= len(s):
                        break

                    if s[index - i] == s[index + i + 1]:
                        if 2*i + 2 > ans:
                            ans = 2*i + 2
                            temp = s[index - i: index + i + 2]
                    else:
                        break
        if ans == 0:
            temp = s[0]
        return temp

