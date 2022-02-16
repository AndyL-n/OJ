"""
author: L
date: 2022/2/16 17:04
"""

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i,val in enumerate(nums):
            num = target - val
            for j in range(i+1, len(nums)):
                if num == nums[j]:
                    return [i, j]
        return [-1, -1]
