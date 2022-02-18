"""
author: L
date: 2022/2/16 20:16
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        index  = [-1 for _ in range(128)]
        left, ans = 0, 0
        for right, val in enumerate(s):
            left = max(left, index[ord(val)] + 1)
            ans = max(ans, right - left + 1)
            index[ord(val)] = right
        return ans