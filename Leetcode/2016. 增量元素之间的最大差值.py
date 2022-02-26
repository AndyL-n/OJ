"""
author: L
date: 2022/2/26 22:40
"""

class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        ans, maxn = 0, 0
        for i in range(len(nums) - 1, -1, -1):
            tmp = nums[i]
            maxn = tmp if tmp > maxn else maxn
            tmp = maxn - tmp
            ans = tmp if tmp > ans else ans
        return ans if ans else -1

