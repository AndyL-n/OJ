"""
author: L
date: 2022/3/6 18:11
"""

class Solution:
    def goodDaysToRobBank(self, nums: List[int], time: int) -> List[int]:
        n = len(nums)
        left, right = [0] * n, [0] * n
        for i in range(1,n):
            if nums[i] <= nums[i-1]:
                left[i] = left[i-1] + 1
        for i in range(n-1, 0, -1):
            if nums[i] >= nums[i-1]:
                right[i-1] = right[i] + 1

        return [i for i in range(time, n - time) if left[i] >= time and right[i] >= time]