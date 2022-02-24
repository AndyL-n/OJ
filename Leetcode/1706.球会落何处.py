"""
author: L
date: 2022/2/24 13:50
"""
class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        ans = [i for i in range(n)]
        for i in range(m):
            row = grid[i] # 当前行
            for j, col in enumerate(ans):
                if col == -1:
                    continue
                if col != n - 1 and row[col] == 1 and row[col + 1] == 1:
                   ans[j] += 1
                elif col != 0 and row[col] == - 1 and row[col - 1] == -1:
                    ans[j] -= 1
                else:
                    ans[j] = -1
        return ans

        # n = len(grid[0])
        # ans = [-1] * n
        # for j in range(n):
        #     col = j  # 球的初始列
        #     for row in grid:
        #         dir = row[col]
        #         col += dir  # 移动球
        #         if col < 0 or col == n or row[col] != dir:  # 到达侧边或 V 形
        #             break
        #     else:  # 成功到达底部
        #         ans[j] = col
        # return ans
