"""
author: L
date: 2022/2/28 12:35
"""

class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        ans = 0
        # 所有可能的选择
        for mask in range(1 << len(requests)):
            cnt = mask.bit_count()
            # 选择个数小于有效值
            if cnt <= ans:
                continue
            flag = [0 for _ in range(n)]
            # 根据选择的需求模拟执行
            for i, (x, y) in enumerate(requests):
                if mask & (1 << i):
                    flag[x] += 1
                    flag[y] -= 1
            if all(x == 0 for x in flag):
                ans = cnt
        return ans
