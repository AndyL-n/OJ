"""
author: L
date: 2022/2/16 17:17
"""

class Solution:
    def trap(self, height: List[int]) -> int:
        i, j = 0, len(height) - 1
        lmax, rmax, ans = 0, 0, 0
        while (i < j):
            lmax = max(height[i], lmax)
            rmax = max(height[j], rmax)
            if (lmax < rmax):
                ans += lmax - height[i]
                i += 1
            else:
                ans += rmax - height[j]
                j -= 1

        return ans

