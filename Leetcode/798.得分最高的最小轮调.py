"""
author: L
date: 2022/3/9 22:29
"""

class Solution:
    def bestRotation(self, nums: List[int]) -> int:
        n = len(nums)
        # nums[i] 能够得分的 k 的取值范围为 [i−(n−1),i−nums[i]]
        ans = [0] * n
        for i, num in enumerate(nums):
            a = (i - (n - 1) + n) % n
            b = (i - nums[i] + n + 1) % n
            ans[a] += 1
            ans[b] -= 1
            if a >= b:
                ans[0] += 1

        sum, maxn, index = 0, 0, -1
        for i, val in enumerate(ans):
            sum += val
            if sum > maxn:
                maxn = sum
                index = i

        return index
