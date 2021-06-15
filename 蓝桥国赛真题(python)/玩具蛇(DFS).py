import sys
import os

# 最终答案
ans = 0
# 状态标记,当前位置是否已经填充数字
visit = [[False] * 4 for i in range(4)]
# 上，右，下，左四个方向
dir_x = [-1, 0, 1, 0]
dir_y = [0, 1, 0, -1]


# 深度搜索
def dfs(x, y, now_number):
    global ans
    """
    :param x: 当前所在的行
    :param y: 当前所在的列
    :param now_number: 当前填充的数字
    :return: 
    """
    # 搜索边界，填完了16个数字就可以
    # 没有进一步的要求
    if now_number == 16:
        ans += 1
        return
    # 搜索
    # 向四个方向
    for i in range(4):
        new_x = x + dir_x[i]
        new_y = y + dir_y[i]
        # 如果没有越界，且当前位置没有填充数字
        if 0 <= new_x <= 3 and 0 <= new_y <= 3 and (not visit[new_x][new_y]):
            # 标记
            visit[new_x][new_y] = True
            # 进行搜索,填下一个数字
            dfs(new_x, new_y, now_number + 1)
            # 回退，取消标记
            visit[new_x][new_y] = False


# 对格子的每一个位置进行试探
for i in range(4):
    for j in range(4):
        visit[i][j] = True
        dfs(i, j, 1)
        visit[i][j] = False

print(ans)
