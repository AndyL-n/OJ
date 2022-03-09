"""
author: L
date: 2022/3/9 22:30
"""


class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        #  差分数组
        nums = [0] * n
        for left, right, inc in bookings:
            nums[left - 1] += inc
            if right < n:
                nums[right] -= inc
            # print(nums)

        for i in range(1, n):
            nums[i] += nums[i - 1]

        return nums
