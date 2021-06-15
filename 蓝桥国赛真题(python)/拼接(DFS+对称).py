import os
import sys


num = 0

def DFS(x,y,vis):
    global num
    dir_x = [1, 0, -1, 0]
    dir_y = [0, -1, 0, 1]
    vis[x][y] = 1;
    if (x == 7) :
##x=7说明已到达右侧边界
        num += 1
        vis[x][y] = 0;
        return;
    for i in range(0,4):
##        四个方向查找
        xx = int(x + dir_x[i])
        yy = int(y + dir_y[i])
##        四个不合法判断条件依次是
##        当y=0时y不可加，否则必不合法（边上形成锯齿形）
##        已超出边界
##        在当前路径被访问过
##        走到了对角线上及其上方，无需继续下去：这等于说在中间挖了个洞
        if ((y == 0 and i == 3) or (xx < 0 or yy < 0) or vis[xx][yy] == 1 or xx <= yy): 
            continue
  
        DFS(xx, yy, vis);
    vis[x][y] = 0;

if __name__ == '__main__':
  n = 8
  for i in range(1,n-1):
    vis = [[0 for i in range(0,n)] for i in range(0,n)]
    DFS(i,i,vis)
  print(num + 2)
