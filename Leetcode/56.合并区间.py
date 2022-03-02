"""
author: L
date: 2022/3/2 15:16
"""

class Solution:
    def merge(self, nums):
        # 左侧 单调有序
        nums.sort(key=lambda x: x[0])
        ans = []
        for num in nums:
            # 如果列表为空，或者当前区间与上一区间不重合，直接添加
            if not ans or ans[-1][1] < num[0]:
                ans.append(num)
            else:
                # 否则的话，我们就可以与上一区间进行合并
                ans[-1][1] = max(ans[-1][1], num[1])
        return ans
