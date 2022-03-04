"""
author: L
date: 2022/3/4 20:03
"""
class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        ans = 0
        length = len(nums)
        for i in range(length - 1):
            maxn, minn = nums[i], nums[i]
            for j in range(i+1, length):
                maxn = max(nums[j], maxn)
                minn = min(nums[j], minn)
                ans += maxn - minn
        return ans
